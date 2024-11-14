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

void reverse_list(){
    struct node *p1, *p2, *p3;
    if(start == NULL){
        return;
    }
    else if(start->link == NULL){
        printf("After reversing\n");
        display();
    }
    else{
        p1 = start;
        p2 = p1->link;
        p3 = p2->link;
        p1->link = NULL;
        p2->link = p1;
        while(p3 != NULL){
            p1 = p2;
            p2 = p3;
            p3 = p3->link;
            p2->link = p1;
        }
        start = p2;
        printf("After reversing\n");
    display();
    }
}

int main(){
    int n, i, m;
    start = NULL;
    printf("Enter the number of nodes you want: ");
    scanf("%d", &n);
    for(i=0; i<n; i++){
        printf("Enter the element no. %d: ", i+1);
        scanf("%d", &m);
        create_list(m);
    }

    display();
    reverse_list();
}