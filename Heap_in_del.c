#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void printHeap(int heap[], int n) {
    for (int i = 0; i < n; ++i)
        printf("%d ", heap[i]);
    printf("\n");
}

void heapify(int heap[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && heap[left] > heap[largest])
        largest = left;
    if (right < n && heap[right] > heap[largest])
        largest = right;

    if (largest != i) {
        swap(&heap[i], &heap[largest]);
        heapify(heap, n, largest);
    }
}

void insert(int heap[], int *n, int value) {
    (*n)++; 
    heap[*n - 1] = value;


    int i = *n - 1;
    while (i != 0 && heap[(i - 1) / 2] < heap[i]) {
        swap(&heap[i], &heap[(i - 1) / 2]); 
        i = (i - 1) / 2;
    }
}

int deleteRoot(int heap[], int *n) {
    int root = heap[0];
    heap[0] = heap[*n - 1]; 
    (*n)--; 

    heapify(heap, *n, 0);

    return root;
}

int main() {
    int heap[100] = {40, 35, 30, 20, 10, 15, 8};
    int n = 7; 

    printf("Orginal heap:\n");
    printHeap(heap, n);

    int value = 50;
    insert(heap, &n, value);

    printf("\nAfter insertion of %d:\n", value);
    printHeap(heap, n);

    int deletedValue = deleteRoot(heap, &n);
    printf("\nDeleted value: %d\n", deletedValue);
    printHeap(heap,n);
    
    return 0;
}
