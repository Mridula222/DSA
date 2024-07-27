#include<stdio.h>
int linearsearch(int arr[],int n);
int main(){
    int n;int index;
    int arr[]={2,4,6,8,10,12,14};
    printf("enter n");
    scanf("%d",&n);
    index=linearsearch(arr,n);
    if(index==-1){
        printf("not found");
    }
    else{
        printf("element found");
    }
}
int linearsearch(int arr[],int n){
    for(int i=0;i<7;i++){
        if(arr[i]==n){
            return i;
        }
       
    }
     return -1;
    
    
    
}