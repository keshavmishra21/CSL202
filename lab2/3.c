#include<stdio.h>
int main(){
int n1, i, n2, j, k;
scanf("%d",&n1);
int A[n1];
for(i=0; i<n1; i++){
scanf("%d", &A[i]);
}
scanf("%d", &n2);
int B[n2];
for(i=0; i<n2; i++){
scanf("%d", &B[i]);
}
int C[n1+n2];
i=0;
j=0;
k=0;
while((i<n1)&&(j<n2)){
if(A[i]<=B[j]){
C[k]=A[i];
i++;
}
else{
C[k]=B[j];
j++;
}
k++;
}
while(i<n1){
C[k]=A[i];
k++;
i++;
}
while(j<n2){
C[k]=B[j];
k++;
j++;
}
for(i=0; i<(n1+n2); i++){
printf("%d ", C[i]);
}
printf("\n");
}


