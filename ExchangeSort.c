#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int *arr, int i, int j) {
    int tmp = arr[i];
    arr[i] = arr[j];
    arr[j] = tmp;
}

void ExchangeSort(int *arr, int n) {
    int i, j;
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (arr[i] > arr[j])
                swap(arr, i, j);
        }
    }
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
    ExchangeSort(arr, size);
    end = clock();

    printf("execution time: %lf\n", (double)(end - start)/CLOCKS_PER_SEC);
    free(arr);

    return 0;
}