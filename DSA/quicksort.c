#include<stdio.h>
#include<stdlib.h>
int part(int a[],int l,int h);
void swap(int* a,int* b);

void quicksort(int a[],int l,int h){
	int q;
	if(l<h){
		q=part(a,l,h);
		quicksort(a,l,q-1);
        quicksort(a,q+1,h);
	}
}
int part(int a[],int l,int h)
{
	int x,i,j;
	x=a[h];
	i=l-1;
	for(j=l;j<h;j++){
		if(a[j]<=x){
			i=i+1;
			swap(&a[i],&a[j]);
		}
	}
	swap(&a[i+1],&a[h]);
	return i+1;
}
void swap(int* a,int* b){
	int temp=*a;
	*a=*b;
	*b=temp;
}
void print(int a[],int size){
	int i;
	for(i=0;i<size;i++){
		printf("%d\t",a[i]);
	}
}
void main(){
	int a[20],size,i;
	printf("Enter size of array\n");
	scanf("%d",&size);
	printf("\nEnter elements\n");
	for(i=0;i<size;i++){
                scanf("%d\t",&a[i]);
        }
	printf("\nUn-Sorted array is:\n");
	print(a,size);
	quicksort(a,0,size-1);
	printf("\nSorted array is:\n");
	print(a,size);
}





