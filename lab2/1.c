#include<stdio.h>

int main(){
int n, i, element, position;
scanf("%d", &n);
int A[n+1];
for(i=0; i<n; i++){
scanf("%d ",&A[i]);
}
scanf("%d", &element);
scanf("%d",&position);
for(i=n; i>=position-1; i--){
A[i+1]=A[i];
}
A[position-1]=element;
n++;
for(i=0; i<n; i++){
printf("%d ",A[i]);
}
printf("\n");
}

