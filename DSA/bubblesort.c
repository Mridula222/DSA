#include<stdio.h>
void bubblesort(int arr[],int n);
int main(){
    int n;
    int arr[]={7,5,6,8,3};
    printf("enter n");
    scanf("%d",&n);
    bubblesort(arr,n);
}
void bubblesort(int arr[],int n){
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;

            }
        }
    }
    printf("sorted array is");
    for(int i=0;i<n;i++){
        printf("%d",arr[i]);
    }
}