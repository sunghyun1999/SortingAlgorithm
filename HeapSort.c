#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int *arr, int i, int j) {
    int tmp = arr[i];
    arr[i] = arr[j];
    arr[j] = tmp;
}

void Siftdown(int *arr, int n, int i) {
    int parent = i;
    int lchild = 2 * parent;
    int rchild = 2 * parent + 1;

    if (lchild <= n && arr[parent] < arr[lchild]) 
        parent = lchild;

    if (rchild <= n && arr[parent] < arr[rchild]) 
        parent = rchild;
    
    if (parent != i) {
        swap(arr, parent, i);
        Siftdown(arr, n, parent);
    }   
}

void makeheap(int *arr, int n) {
    int i;
    for (i = n / 2; i >= 1; i--) 
        Siftdown(arr, n, i);
}

void removekeys(int *arr, int n) { 
    for (int i = n; i >= 1; i--) {
        swap(arr, 1, i);
        Siftdown(arr, i - 1, 1);
    }
}

void HeapSort(int *arr, int n) {
    makeheap(arr, n);
    removekeys(arr, n);
}

int main() {
    int i;
    int size = 100000;
    int *arr = (int *)malloc(sizeof(int) * size + 1);
    double start, end;

    srand((unsigned int)time(NULL));
    arr[0] = -1;
    for (i = 1; i <= size; i++) 
        arr[i] = rand() % 1000 + 1;

    start = clock();
    HeapSort(arr, size);
    end = clock();

    printf("execution time: %lf\n", (double)(end - start)/CLOCKS_PER_SEC);
    free(arr);

    return 0;
}