#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void Merge(int front, int back, int *U, int *V, int *arr) {
    int i = 0, j = 0, k = 0;
    while (i < front && j < back) {
        if (U[i] < V[j]) {
            arr[k] = U[i];
            i++;
        }
        else {
            arr[k] = V[j];
            j++;
        }
        k++;
    }
    if (i >= front)
        for (; j < back; j++)
            arr[k++] = V[j];
    else
        for(; i < front; i++)
            arr[k++] = U[i];
}

void MergeSort(int *arr, int n) {
    int i;
    int front = n / 2;              
    int back = n - front;
    int *U = (int *)malloc(sizeof(int) * front);
    int *V = (int *)malloc(sizeof(int) * back);

    if (n > 1) {
        for (i = 0; i < front; i++)
            U[i] = arr[i];
        for (i = 0; i < back; i++)
            V[i] = arr[i + front];
        MergeSort(U, front);
        MergeSort(V, back);
        Merge(front, back, U, V, arr);
    }
    free(U);
    free(V);
}   

int main() {
    int i;
    int size = 100000;
    int *arr = (int *)malloc(sizeof(int) * size);
    double start, end;

    srand((unsigned int)time(NULL));
    for (i = 0; i < size; i++) 
        arr[i] = rand() % 1000 + 1;

    start = clock();
    MergeSort(arr, size);
    end = clock();

    printf("execution time: %lf\n", (double)(end - start)/CLOCKS_PER_SEC);
    free(arr);

    return 0;
}