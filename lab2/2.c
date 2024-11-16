#include<stdio.h>
int main(){
int n, i, position;
scanf("%d",&n);
int A[n];
for(i=0; i<n; i++){
scanf("%d",&A[i]);
}
scanf("%d",&position);
for(i=position-1; i<n-1; i++){
A[i]=A[i+1];
}
n--;
for(i=0; i<n; i++){
printf("%d ", A[i]);
}
printf("\n");
}
