#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};
struct node *start;

void Enqueue(int data){
    struct node *q, *tmp;
    tmp=malloc(sizeof(struct node));
    tmp->data=data;
    tmp->next=start;
    start=tmp;

    
}
void Dequeue(){
    struct node *tmp, *q;
    q=malloc(sizeof(struct node));
    q = start;
    start=start->next;
    free(q);
}
void peek(){
    struct node *q;
    q=start;
    if(start==NULL){
        printf("Empty\n");
    }
    else{
        while(q->next!=NULL){
            q=q->next;

        }
        printf("%d", q->data);
    }
}
void print(){
    struct node *q;
    q=start;
    if(start==NULL){
        printf("EMPTY\n");
        
    }
    else{
        while(q!=NULL){
            printf("%d ",q->data);
            q=q->next;
        }
        printf("\n");
        
    }
}
int main(){
    int choice, value, exitloop=0;
    while(1){
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Peek\n");
        printf("4. print\n");
        printf("5.Exit\n");
        scanf("%d",&choice);
        switch(choice){
            case 1:
            printf("Enter the element: ");
            scanf("%d",&value);
            Enqueue(value);
            break;
            case 2:
            Dequeue();
            break;
            case 3:
            peek();
            break;
            case 4:
            print();
            break;
            case 5:
            exitloop=1;
            break;
            default:
            printf("Invalid choice\n");
        }
        if(exitloop==1){
            break;
        }
    }
}
