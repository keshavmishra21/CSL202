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
    if(start == NULL){
        start = tmp;
        tmp->link = start;
    }
    else{
        q = start;
        while((q->link) != start){
            q = q->link;
        }
        q->link = tmp;
        tmp->link = start;
    }
}

void add_at_beg(int data){
    struct node *tmp, *q;
    tmp = malloc(sizeof(struct node));
    tmp->info = data;
    q = start;
    if(start == NULL){
        start = tmp;
        tmp->link = start;
    }
    else{
        while((q->link) != start){
            q = q->link;
        }
        q->link = tmp;
        tmp->link = start;
        start = tmp;
    }
}

void add_at_end(int data){
    struct node *tmp, *q;
    tmp = malloc(sizeof(struct node));
    tmp->info = data;
    if(start == NULL){
        start = tmp;
        tmp->link = start;
    }
    else{
        q = start;
        while((q->link) != start){
            q = q->link;
        }
        q->link = tmp;
        tmp->link = start;
    }
}

void add_before(int value, int data){
    struct node *tmp, *q, *r;
    tmp = malloc(sizeof(struct node));
    tmp->info = data;
    if(start == NULL){
        printf("The list is empty\n");
        return;
    }
    else if((start->info) == value){
        tmp->link = start;
        start->link = tmp;
        start = tmp;
    }
    else{
        q = start;
        r = start;
        r = r->link;
        while((r->info) != value){
            q = q->link;
            r = r->link;
        }
        tmp->link = q->link; 
        q->link = tmp;
    }
}

void delete_at_beg(){
    struct node *tmp, *q;
    if(start == NULL){
        return;
    }
    else if((start->link) == start){
        tmp = start;
        start = NULL;
        free(tmp);
    }
        else{
        tmp = start;
        q = start;
        while((q->link) != start){
            q = q->link;
        }
        q->link = start->link;
        start = start->link;
        free(tmp);
    }
}

void delete_at_end(){
    struct node *tmp, *q, *r;
    q = start;
    r = start;
    if(start == NULL){
        return;
    }
    else if((start->link) == start){
        tmp = start;
        start = NULL;
        free(tmp);
    }
    else{
        r = r->link;
        while((r->link) != start){
            q = q->link;
            r = r->link;
        }
        q->link = start;
        free(r);
    }
}

void delete(int data){
    struct node *q, *r;
    q = start;
    if(start == NULL){
        return;
    }
    else if((start->info) == data){
        if((start->link) == start){
            q = start;
            start = NULL;
            free(q);
        }
        else{
            q = start;
            while((q->link) != start){
                q = q->link;
            }
            q->link = start->link;
            r = start;
            start = start->link;
            free(r);
        }
    }
    else{
        r = start;
        r = r->link;
        while((r->info) != data){
            q = q->link;
            r = r->link;
        }
        q->link = r->link;
        free(r);
    }
}

void display(){
    struct node *q;
    q = start;
    if(start == NULL){
        printf("The list is empty\n");
        return;
    }
    else{
        printf("The list is: \n");
        while((q->link) != start){
            printf("%d ", q->info);
            q = q->link;
        }
        printf("%d \n", q->info);
    }
}

int main(){
    int choice, n, i, m, val, exitloop;
    exitloop = 0;
    while(1){
        printf("1. Create a circular linked-list\n");
        printf("2. Insert a node at the beginning of the circular linked list\n");
        printf("3. Insert a node at the end of the circular linked list\n");
        printf("4. Insert a node before a node with a given value\n");
        printf("5. Delete the node at the beginning of the circular linked list\n");
        printf("6. Delete the node at the end of the circular linked list\n");
        printf("7. Delete the node with a given value\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice){
            case 1:
                start = NULL;
                printf("How many nodes you want: ");
                scanf("%d",&n);
                for(i=0; i<n; i++){
                    printf("Enter the element no. %d: ", i+1);
                    scanf("%d", &m);
                    create_list(m);
                }
                break;
            case 2:
                printf("Enter the element you want to insert at the beginning: ");
                scanf("%d", &m);
                add_at_beg(m);
                break;
            case 3:
                printf("Enter the element you want to insert at the end: ");
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
                printf("Enter the value of node that you want to delete: ");
                scanf("%d", &m);
                delete(m);
                break;
            case 8:
                exitloop = 1;
                break;
            default:
                printf("Invalid choice");    
        }
        if(exitloop == 1){
            break;
        }
    }
    display();
}