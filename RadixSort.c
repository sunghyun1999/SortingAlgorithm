#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct _node {
	int data;
	struct _node* link;
} Node;

typedef struct queue {
	Node* front;
	Node* rear;
} Queue;

void QInit(Queue* pq) {
	pq->front = NULL;
	pq->rear = NULL;
}

int IsEmpty(Queue* pq) {
	if (pq->front == NULL) return 1;
	else return 0;
}

void Enqueue(Queue* pq, int data) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->link = NULL;
	newNode->data = data;

	if (IsEmpty(pq)) {
		pq->front = newNode;
		pq->rear = newNode;
	}
	else {
		pq->rear->link = newNode;
		pq->rear = newNode;
	}
}

int Dequeue(Queue* pq) {
	Node* delNode;
	int ret;

	delNode = pq->front;
	ret = delNode->data;
	pq->front = pq->front->link;

	free(delNode);
	return ret;
}

int getMax(int *arr, int n) {
    int i, max = arr[0], count = 1;
    for (int i = 1; i < n; i++) {
        if (arr[i] > max)
            max = arr[i];
    }
    while (max / 10 != 0) {
        max /= 10;
        count++;
    }
    return count;
}

void RadixSort(int *arr, int n) {
    Queue list[10];
    int i, j, k, rdx, div = 1;
    int max = getMax(arr, n);
    
    for (i = 0; i < 10; i++)
        QInit(&list[i]);
    
    for (i = 0; i < max; i++) {
        for (j = 0; j < n; j++) {
            rdx = (arr[j] / div) % 10;
            Enqueue(&list[rdx], arr[j]);
        }
        k = 0;
        for (j = 0; j < 10; j++) {
            while(!IsEmpty(&list[j])) 
                arr[k++] = Dequeue(&list[j]);
        }
        div *= 10;
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
    RadixSort(arr, size);
    end = clock();

    printf("execution time: %lf\n", (double)(end - start)/CLOCKS_PER_SEC);
    free(arr);

    return 0;
}