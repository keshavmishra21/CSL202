#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};
struct node *start;

void push(int data){
    struct node *tmp, *q;
    tmp= malloc(sizeof(struct node));
    tmp->data=data;
    tmp->next=NULL;
    if(start==NULL){
        start=tmp;
    }
    else{
        q=start;
        while(q->next!=NULL){
            q=q->next;
        }
        q=tmp;

    }
}
void pop(){
    struct node *q,*r,*tmp;
    tmp=malloc(sizeof(struct node));
    q =start;
    r=start;
    if(start ==NULL){
        printf("The array is empty");

    }
    else{
        q=q->next;
        while(q->next!=NULL){
            q=q->next;
            r=r->next;
        }

        printf("Element popped: %d",q->data);
        r->next=NULL;
        tmp=q;
        free(q);


    }

}
void peek(){
    struct node *q;
    q=start;
    if(start==NULL){
        printf("The stack is empty");
    }
    else{
        while(q->next!=NULL){
            q=q->next;
        }
        printf("The stack's top is %d\n", q->data);
    }
}
int main(){
    int choice, value, exitloop=0;
    while(1){
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Exit\n");
        scanf("%d", &choice);
        switch(choice){
            case 1:
            start = NULL;
            printf("enter the element: ");
            scanf("%d",&value);
            push(value);
            break;
            case 2:
            pop();
            break;
            case 3:
            peek();
            break;
            case 4:
            exitloop = 1;
            break;
            default:
            printf("Invalid choice");
        }
        if(exitloop==1){
            break;
        }

    }
}