#include<stdio.h>
#include<stdlib.h>

int queue[100];
int front = -1, rear = -1;

int empty(){
    return (front == -1 || front>rear);
}
int full(){
    return (rear==99);

}
void Enqueue(int value){
    if(full()){
        printf("Overflow");

    }
    else{
        if(front == -1){
            front = 0;
        }
        rear++;
        queue[rear]=value;

    }
}
void Dequeue(){
    if(empty()){
        printf("Underflow");
    }
    else{
        int dequeue=queue[front];
        front++;
        if(front>rear){
            front=rear-1;
        }
        printf("Dequeued: %d",dequeue);

    }
}

void peek(){
    if(empty()){
        printf("Empty");
        return;
    }
    else{
        printf("Front element: %d", queue[front]);
    }
}
void print(){
    if(empty())
{
    printf("Empty");
}
else{
printf("Elements: ");
for(int i=front; i<=rear; i++){
    printf("%d ", queue[i]);
}
printf("\n");
}
}
int main(){
    int choice, value, exitloop=0;
    while(1){
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. peek\n");
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