#include<stdio.h>
#include<stdlib.h>

int stack[100];
int top=-1;

void push(int value){
    if(top==99){
        printf("Overflow");

    }
    else{
        top++;
        stack[top]=value;

    }

}
void pop(){
    if(top==-1){
        return ;
    }
    else{
        int popped_value=stack[top];
        printf("popped value=%d",popped_value);
        top--;
        
    }
}
void peek(){
    if(top==-1){
        printf("Stack is empty");
        return;
    }
    else{
        printf("The top element is: %d \n",stack[top]);
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
            printf("Enter the element to push: ");
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
            exitloop=1;
            break;
            default:
            printf("Invalid choice");


        }
        if(exitloop==1){
            break;
        }

    }
}