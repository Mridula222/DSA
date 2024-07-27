#include <stdio.h>
#include <stdlib.h>

// Function to partition the array
int part(int a[], int l, int h);

// Function to swap two elements
void swap(int* a, int* b);

// Quicksort function
void quicksort(int a[], int l, int h) {
    int q;
    if (l < h) {
        q = part(a, l, h);
        quicksort(a, l, q - 1);
        quicksort(a, q + 1, h);
    }
}
// Partition function
int part(int a[], int l, int h) {
    int x = a[h];
    int i = l - 1;
    for (int j = l; j < h; j++) {
        if (a[j] <= x) {
            i = i + 1;
            swap(&a[i], &a[j]);
        }
    }
    swap(&a[i + 1], &a[h]);
    return i + 1;
}
// Swap function
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
} 
// Function to print the array
void print(int a[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d\t", a[i]);
    }
    printf("\n");
}

// Main function
int main() {
    int a[20], size;

    printf("Enter size of array: ");
    scanf("%d", &size);

    printf("Enter elements:\n");
    for (int i = 0; i < size; i++) {
        scanf("%d", &a[i]);
    }

    printf("Un-Sorted array is:\n");
    print(a, size);

    quicksort(a, 0, size - 1);

    printf("Sorted array is:\n");
    print(a, size);

    return 0;
}
