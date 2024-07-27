#include <stdio.h>
void swap(int *a, int *b);
void heapify(int a[], int n, int i)
{
	int largest = i;
	int left = 2 * i + 1;
	int right = 2 * i + 2;
	if (left < n && a[left] > a[largest])
		largest = left;
	if (right < n && a[right] > a[largest])
		largest = right;
	if (largest != i)
	{
		// int temp=a[i];
		// a[largest]=a[i];
		// a[i]=temp;
		swap(&a[i], &a[largest]);
		heapify(a, n, largest);
	}
}
void heapsort(int a[], int n)
{
	int i;
	for (i = n / 2 - 1; i >= 0; i--)
		heapify(a, n, i);
	for (i = n - 1; i >= 0; i--)
	{
		int temp = a[0];
		a[0] = a[i];
		a[i] = temp;
		heapify(a, i, 0);
	}
	printf("Sorted array-\n");
	for (i = 0; i < 5; i++)
		printf("%d\t", a[i]);
	printf("\n");
}
void main()
{
	int a[100], i, n;
	printf("Enter number of elements in array-");
	scanf("%d", &n);
	printf("Enter array elements-");
	for (i = 0; i < n; i++)
		scanf("%d", &a[i]);
	heapsort(a, n);
}
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}