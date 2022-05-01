#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int *arr, int i, int j) {
    int tmp = arr[i];
    arr[i] = arr[j];
    arr[j] = tmp;
}

int Partition(int *arr, int low, int high) {
    int i, j, pivot;

    pivot = arr[low];
    j = low;
    for (i = low + 1; i <= high; i++) {
        if (arr[i] < pivot) {
            j++;
            swap(arr, i, j);
        }
    }
    swap(arr, low, j);
	return j;
}

void QuickSort(int *arr, int low, int high) {
	if (low < high) {
		int pivot = Partition(arr, low, high);
		QuickSort(arr, low, pivot - 1);
		QuickSort(arr, pivot + 1, high);
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
    QuickSort(arr, 0, size - 1);
    end = clock();

    printf("execution time: %lf\n", (double)(end - start)/CLOCKS_PER_SEC);
    free(arr);

    return 0;
}