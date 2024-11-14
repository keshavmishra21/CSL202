#include <stdio.h>
#include <stdlib.h>

struct node{
    struct node *prev;
    int info;
    struct node *next;
};
struct node *start;

void create_list(int data){
    struct node *tmp, *q;
    tmp = malloc(sizeof(struct node));
    tmp->info = data;
    if(start == NULL){
        tmp->prev = NULL;
        tmp->next = NULL;
        start = tmp;
    }
    else{
        q = start;
        while((q->next) != NULL){
            q = q->next;
        }
        q->next = tmp;
        tmp->prev = q;
        tmp->next = NULL;
    }
}

void add_at_beg(int data){
    struct node *tmp;
    tmp = malloc(sizeof(struct node));
    tmp->info = data;
    tmp->next = start;
    tmp->prev = NULL;
    start = tmp;
}

void add_at_end(int data){
    struct node *tmp, *q;
    tmp = malloc(sizeof(struct node));
    tmp->info = data;
    if(start == NULL){
        tmp->prev = NULL;
        tmp->next = NULL;
        start = tmp;
    }
    else{
        q = start;
        while((q->next) != NULL){
            q = q->next;
        }
        q->next = tmp;
        tmp->next = NULL;
        tmp->prev = q;
    }
}

void add_before(int value, int data){
    struct node *tmp, *q, *r;
    tmp = malloc(sizeof(struct node));
    tmp->info = data;
    if(start == NULL){
        return;
    }
    else if((start->info) == value){
        tmp->next = start;
        tmp->prev = NULL;
        start = tmp;
    }
    else{
        q = start;
        while((q->info) != value){
            q = q->next;
        }
        r = q->prev;
        r->next = tmp;
        tmp->prev = r;
        q->prev = tmp;
        tmp->next = q;
    }
}

void delete_at_beg(){
    struct node *tmp, *q, *r;
    if(start == NULL){
        return;
    }
    else if((start->next) == NULL){
        tmp = start;
        start = NULL;
        free(tmp);
    }
    else{
        tmp = start;
        start = tmp->next;
        r->prev = NULL;
        free(tmp);
    }
}

void delete_at_end(){
    struct node *tmp, *q, *r;
    if(start == NULL){
        return;
    }
    else if((start->next) == NULL){
        tmp = start;
        start = NULL;
        free(tmp);
    }
    else{
        q = start;
        while((q->next) != NULL){
            q = q->next;
        }
        r = q->prev;
        r->next = NULL;
        free(q);
    }
}

void delete(int data){
    struct node *tmp, *q, *r;
    if(start == NULL){
        return;
    }
    else if((start->next) == NULL){
        if((start->info) == data){
            tmp = start;
            start = NULL;
            free(tmp);
        }
        else{
            printf("Element not found\n");
        }
    }
    else{
        q = start;
        while((q->info) != data){
            q = q->next;
        }
        r = q->prev;
        r->next = q->next;
        tmp = q->next;
        tmp->prev = r;
        free(q);
    }
}

void display(){
    struct node *q;
    if(start == NULL){
        printf("The list is empty\n");
        return;
    }
    q = start;
    printf("The list is: \n");
    while(q != NULL){
        printf("%d ", q->info);
        q = q->next;
    }
    printf("\n");
}

int main(){
    int choice, n, i, m, val, exitloop;
    exitloop = 0;
    while(1){
        printf("1. Create a doubly linked-list\n");
        printf("2. Insert a node at the beginning of the list\n");
        printf("3. Insert a node at the end of the list\n");
        printf("4. Insert a node before a node with a given value\n");
        printf("5. Delete the node at the beginning of the list\n");
        printf("6. Delete the node at the end of the list\n");
        printf("7. Delete the node with a given value\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                start = NULL;
                printf("How many nodes you want: ");
                scanf("%d", &n);
                for(i=0; i<n; i++){
                    printf("Enter the element no. %d: ", i+1);
                    scanf("%d", &m);
                    create_list(m);
                }
                break;
            case 2:
                printf("Enter the element you would like to insert at the beginning: ");
                scanf("%d", &m);
                add_at_beg(m);
                break;
            case 3:
                printf("Enter the element you would like to insert at the end: ");
                scanf("%d", &m);
                add_at_end(m);
                break;
            case 4:
                printf("Enter the element of the node before which you would like to insert the new node: ");
                scanf("%d", &val);
                printf("Enter the element of the new node: ");
                scanf("%d", &m);
                add_before(val, m);
                break;
            case 5:
                delete_at_beg();
                break;
            case 6:
                delete_at_end();
                break;
            case 7:
                printf("Enter the element of the node that you would like to delete: ");
                scanf("%d", &m);
                delete(m);
                break;
            case 8:
                exitloop = 1;
                break;
            default:
                printf("Invalid Choice\n");
        }
        if(exitloop == 1){
            break;
        }
    }
    display();
}
