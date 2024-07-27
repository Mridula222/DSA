#include <stdio.h>

int binsearch(int arr[], int key);

int main() {
    int key;
    int arr[] = {2, 4, 6, 8, 10, 12, 14};
    printf("Enter key: ");
    scanf("%d", &key);
    int loc = binsearch(arr, key);
    if (loc == -1) {
        printf("Element not found\n");
    } else {
        printf("Element is found at loc %d\n", loc);
    }
    return 0;
}

int binsearch(int arr[], int key) {
    int start = 0;
    int end = 6; // As we know the size of the array is 7, we can directly specify the end index.
    while (start <= end) {
        int mid = (start + end) / 2;
        if (arr[mid] == key) {
            return mid;
        }
        if (arr[mid] < key) {
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }
    return -1;
}
