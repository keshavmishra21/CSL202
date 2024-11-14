#include <stdio.h>
#include <stdlib.h>

struct node{
    int info;
    struct node *link;
};
struct node *start;

void create_list(int data){
    struct node *q, *tmp;
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

void add_at_beg(int data){
    struct node *tmp;
    tmp = malloc(sizeof(struct node));
    tmp->info = data;
    tmp->link = start;
    start = tmp;
}

void add_at_end(int data){
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

void add_before(int value, int data){
    struct node *tmp, *q, *r;
    tmp = malloc(sizeof(struct node));
    tmp->info = data;
    q = start;
    if((q->info) == value){
        tmp->link = start;
        start = tmp;
    }
    else{
        r = start;
        q = q->link;
        while((q->info) != value){
            q = q->link;
            r = r->link;
        }
        tmp->link = r->link;
        r->link = tmp;
    }
}

void delete_at_beg(){
    struct node *tmp;
    tmp = start;
    start = start->link;
    free(tmp);
}

void delete_at_end(){
    struct node *q, *r;
    q = start;
    if((q->link) == NULL){
        start = start->link;
        free(q);
    }
    else{
        r = start;
        q = q->link;
        while((q->link) != NULL){
            q = q->link;
            r = r->link;
        }
        r->link = q->link;
        free(q);
    }
}

void delete(int data){
    struct node *q, *r;
    q = start;
    if((q->info) == data){
        start = start->link;
        free(q);
    }
    else{
        r = start;
        q = q->link;
        while((q->info) != data){
            q = q->link;
            r = r->link;
        }
        r->link = q->link;
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
        q = q->link;
    }
    printf("\n");
}

int main(){
    int choice, n, i, m, val, exitloop;
    exitloop = 0;
    while(1){
        printf("1. Create a linked-list\n");
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
                scanf("%d",&n);
                for(i=0; i<n; i++){
                    printf("Enter the element no. %d: ", i+1);
                    scanf("%d", &m);
                    create_list(m);
                }
                break;
            case 2:
                printf("Enter the element: ");
                scanf("%d", &m);
                add_at_beg(m);
                break;
            case 3:
                printf("Enter the element: ");
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
                printf("Enter the element of the node that you wan to delete: ");
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
    
