#include<stdio.h>
#include<limits.h>
#define MAX_SIZE 100
struct priorityQueue{
    int heap[100];
    int size;
};

void swap(int *x, int *y){
    int tmp = *x;
    *x = *y;
    *y = tmp;
}
void heapify(struct priorityQueue *Q, int i) {
    int largest = i;  
    int left = 2 * i + 1; 
    int right = 2 * i + 2;  

   
    if (left < Q->size && Q->heap[left] > Q->heap[largest])
        largest = left;

   
    if (right < Q->size && Q->heap[right] > Q->heap[largest])
        largest = right;

    
    if (largest != i) {
        swap(&Q->heap[i], &Q->heap[largest]);

       
        heapify(Q, largest);
    }
}
void insert(struct priorityQueue *Q, int x) {
    if (Q->size == MAX_SIZE) {
        printf("Queue overflow\n");
        return;
    }

    
    Q->size++;
    int i = Q->size - 1;
    Q->heap[i] = x;

    
    while (i != 0 && Q->heap[(i - 1) / 2] < Q->heap[i]) {
        swap(&Q->heap[i], &Q->heap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

int maximum(struct priorityQueue *Q) {
    if (Q->size <= 0) {
        printf("Queue underflow\n");
        return INT_MIN;
    }
    return Q->heap[0];
}
int extractMax(struct priorityQueue *Q) {
    if (Q->size <= 0) {
        printf("Queue underflow\n");
        return INT_MIN;
    }
    if (Q->size == 1) {
        Q->size--;
        return Q->heap[0];
    }

    
    int root = Q->heap[0];
    Q->heap[0] = Q->heap[Q->size - 1];
    Q->size--;

    
    heapify(Q, 0);

    return root;
}
void increaseKey(struct priorityQueue *Q, int i, int k) {
    if (k<0) {
        printf("Can not decrease\n");
        return;
    }

    Q->heap[i] += k;

    while (i != 0 && Q->heap[(i - 1) / 2] < Q->heap[i]) {
        swap(&Q->heap[i], &Q->heap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

int main(){
    struct priorityQueue Q;
    Q.size=0;
    int n, i, x, choice, index, k, exitloop=0;
    printf("Enter the number of elements to insert into the priority queue: ");
    scanf("%d",&n);
    for(i = 0; i<n; i++){
        printf("Enter element %d: ", i + 1);
        scanf("%d", &x);
        insert(&Q, x);
    }
    while(1){
        printf("\nChoose an operation:\n");
        printf("1. Insert a new element\n");
        printf("2. Get maximum element\n");
        printf("3. Extract maximum element\n");
        printf("4. Increase key of an element\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
            printf("Enter the element to insert: ");
            scanf("%d", &x);
            insert(&Q, x);
            break;
            case 2:
            printf("Maximum element is %d\n", maximum(&Q));
            break;
            case 3:
            printf("Extracted max element is %d\n", extractMax(&Q));
            break;
            case 4:
            printf("Enter the index of the element to increase: ");
            scanf("%d", &index);
            printf("Enter the value by which to increase: ");
            scanf("%d", &k);
            increaseKey(&Q, index, k);
            break;
            case 5:
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