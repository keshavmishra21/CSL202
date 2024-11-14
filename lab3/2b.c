#include <stdio.h>
#include <stdlib.h>

struct node{
    int info;
    struct node *link;
};
struct node *start;

void create_list(int data){
    struct node *tmp, *q;
    tmp = malloc(sizeof(struct node));
    tmp->info = data;
    tmp->link = NULL;
    if(start == NULL){
        start = tmp;
    }
    else{
        q = start;
        while((q->link) != NULL){
            q = q->link;
        }
        q->link = tmp;
    }
}

void display(){
    struct node *q;
    if(start == NULL){
        printf("The list is empty");
    }
    else if((start->link) == NULL){
        printf("The list is: \n");
        printf("%d", start->info);
    }
    else{
        q = start;
        printf("The list is: \n");
        while(q != NULL){
            printf("%d ", q->info);
            q = q->link;
        }
    }
    printf("\n");
}

void reverse(struct node *p){
    if(start == NULL){
        return;
    }
    else{
        struct node *q;
        if((p->link) == NULL){
            start = p;
            return;
        }
        reverse(p->link);
        q = p->link;
        q->link = p;
        p->link = NULL;
    }
}


int main(){
    int n, i, m;
    printf("How many nodes you want: ");
    scanf("%d", &n);
    start = NULL;
    for(i=0; i<n; i++){
        printf("Enter the element no. %d: ", i+1);
        scanf("%d", &m);
        create_list(m);
    }
    display();
    if(start != NULL){
    reverse(start);
    printf("After reversing: \n");
    display();
    }
}