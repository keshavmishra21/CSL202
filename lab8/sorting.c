#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void insertionSort(int arr[], int n) {
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void merge(int arr[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[n1], R[n2];

    for (int i = 0; i < n1; i++) L[i] = arr[l + i];
    for (int j = 0; j < n2; j++) R[j] = arr[m + 1 + j];

    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) arr[k] = L[i++];
        else arr[k] = R[j++];
        k++;
    }

    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}

void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

void mergeSortWrapper(int arr[], int n) {
    mergeSort(arr, 0, n - 1);
}

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void heapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest]) largest = left;
    if (right < n && arr[right] > arr[largest]) largest = right;

    if (largest != i) {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) heapify(arr, n, i);
    for (int i = n - 1; i > 0; i--) {
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        heapify(arr, i, 0);
    }
}

void generateRandomArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100000;
    }
}

double measureSortingTime(void (*sortFunc)(int[], int), int arr[], int n) {
    clock_t start, end;
    double totalTime = 0.0;

    for (int i = 0; i < 3; i++) {
        int *tempArr = (int*)malloc(n * sizeof(int));
        for (int j = 0; j < n; j++) tempArr[j] = arr[j];

        start = clock();
        sortFunc(tempArr, n);
        end = clock();

        totalTime += ((double)(end - start)) * 1000 / CLOCKS_PER_SEC;
        free(tempArr);
    }

    return totalTime / 3;
}

int main() {
    srand(time(0));

    int sizes[] = {500, 1000, 5000, 10000, 20000, 50000, 100000};
    int numSizes = sizeof(sizes) / sizeof(sizes[0]);
    FILE *fp = fopen("sorting_results.csv", "w");

    if (!fp) {
        printf("Failed to open file for writing.\n");
        return 1;
    }

    fprintf(fp, "Algorithm,Array Size,Time (Milliseconds)\n");

    for (int i = 0; i < numSizes; i++) {
        int n = sizes[i];
        int arr[n];
        generateRandomArray(arr, n);

        double insertionSortTime = measureSortingTime(insertionSort, arr, n);
        double mergeSortTime = measureSortingTime(mergeSortWrapper, arr, n);
        double bubbleSortTime = measureSortingTime(bubbleSort, arr, n);
        double heapSortTime = measureSortingTime(heapSort, arr, n);

        printf("Array Size %d: \n", n);
        printf("Insertion Sort: %.5f ms\n", insertionSortTime);
        printf("Merge Sort: %.5f ms\n", mergeSortTime);
        printf("Bubble Sort: %.5f ms\n", bubbleSortTime);
        printf("Heap Sort: %.5f ms\n", heapSortTime);

        fprintf(fp, "Insertion Sort,%d,%.5f\n", n, insertionSortTime);
        fprintf(fp, "Merge Sort,%d,%.5f\n", n, mergeSortTime);
        fprintf(fp, "Bubble Sort,%d,%.5f\n", n, bubbleSortTime);
        fprintf(fp, "Heap Sort,%d,%.5f\n", n, heapSortTime);
    }

    fclose(fp);
    printf("Results saved to sorting_results.csv\n");

    return 0;
}
