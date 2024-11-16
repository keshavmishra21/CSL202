#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

struct node
{
int info;
struct node *link;
}*start;

void create_list(int data){
struct node *q, *temp;
temp=malloc(sizeof(struct node));
temp->info=data;
temp->link=NULL;
if(start==NULL){
start=temp;
}
else{
q=start;
while(q->link!=NULL){
q=q->link;
}
q->link=temp;
}
}

void addatbeg(int data){
struct node *temp;
temp=malloc(sizeof(struct node));
temp->info=data;
temp->link=start;
start=temp;
}

void addatlast(int data){
struct node *temp, *q;
q=start;
while(q->link!=NULL){
q=q->link;
}
temp=malloc(sizeof(struct node));
temp->link=q->link;
temp->info=data;
q->link=temp;
}

void delatbeg(){
struct node *temp, *q;
temp=start;
start=start->link;
free(temp);
}

void delatend(){
struct node *temp, *q;
q=start;
while(q->link!=NULL){
q=q->link;
}
temp=q->link;
free(temp);
}

void display(){
struct node *q;
q=start;
printf("List is: ");
while(q!=NULL){
printf("%d",q->info);
q=q->link;
}
printf("\n");
}

int main(){
int n, i, m, choice;
start=NULL;
printf("Number of nodes: ");
scanf("%d",&n);
for(i=0; i<n; i++){
printf("Enter the element: ");
scanf("%d",&m);
create_list(m);
}
display();
printf("1. Insertion at the beginning.\n2. Insertion at the end.\n3. Deletion at the beginning.\n4. Deletion at the end.\n5. Exit.");
scanf("%d",&choice);
switch(choice){
case 1: 
printf("Enter the element: ");
scanf("%d",&m);
addatbeg(m);
break;

case 2:
printf("Enter the element: ");
scanf("%d",&m);
addatlast(m);
break;

case 3:
delatbeg();
break;

case 4:
delatend();
break;

default:
printf("Wrong choice.");
}
display();
}


