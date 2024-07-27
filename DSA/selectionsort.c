#include<stdio.h>
void selectionsort(int arr[],int n);
int main(){
    int n;
    int arr[]={5,3,7,1,8};
    printf("enter n");
    scanf("%d",&n);
    selectionsort(arr,n);
}
void selectionsort(int arr[],int n){
    int i,j;
    for(i=0;i<n-1;i++){
        int smallest=i;
        for(j=i+1;j<n;j++){
            if(arr[smallest]>arr[j]){
                smallest=j;
            }
        }
        int temp=arr[smallest];
        arr[smallest]=arr[i];
        arr[i]=temp;
    }
    printf("sorted array is");
    for(i=0;i<n;i++){
        printf("%d",arr[i]);
    }
}