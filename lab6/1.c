#include<stdio.h>

void swap(int *x, int *y){
    int tmp;
    tmp = *x;
    *x = *y;
    *y = tmp;
}

void heapify(int A[], int n, int i){
    int largest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;
    if(left<n && A[left]>A[largest]){
        largest = left;
    }
    if(right<n && A[right]>A[largest]){
        largest = right;
    }
    if(largest != i){
        swap(&A[i], &A[largest]);
        heapify(A, n, largest);
    }
}

void buildMaxHeap(int A[], int n){
    int i;
    for(i=(n/2)-1; i>=0; i--){
        heapify(A, n, i);
    }
}

void printtArray(int A[], int n){
    int i;
    for(i=0; i<n; i++){
        printf("%d ",A[i]);
    }
    printf("\n");
}
int main(){
    int n, i;
    printf("Enter the number of elements in the array: ");
    scanf("%d",&n);
    int A[n];
    printf("Enter the elements of the array: ");
    for(i=0; i<n; i++){
        scanf("%d",&A[i]);
    }
    buildMaxHeap(A, n);
    printf("Max Heap Array: \n");
    printtArray(A, n);
    return 0;
}