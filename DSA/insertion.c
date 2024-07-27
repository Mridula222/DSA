#include<stdio.h>
void insertionsort(int arr[],int n);
int main(){
    int arr[]={5,3,4,7,2};
    int n;
    printf("enter n");
    scanf("%d",&n);
    insertionsort(arr,n);
    
}
void insertionsort(int arr[],int n){
    for(int i=1;i<n;i++){
        int current=arr[i];
        int j=i-1;
        while(j>=0 &&current<arr[j]){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=current;
    }
    printf("sorted array is:");
    for(int i=0;i<5;i++){
        printf("%d",arr[i]);
    }

}
