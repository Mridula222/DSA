#include<stdio.h>
 int main(){
    int n,m,i,j,a[10][10];
    printf("Enter no. of rows and columns");
    scanf("%d%d",&n,&m);
    printf("Enter of elements");
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            scanf("%d",&a[i][j]);
        }
    }
    int c=0;
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            if(a[i][j]!=0){
                c++;
            }
        }
    }
    if(c<(n*m)/2){
        int rm[10][10];
        int temp=1; 
        rm[0][0]=n;
        rm[0][1]=m;
        rm[0][2]=c;
        for(i=0;i<n;i++){
            for(j=0;j<m;j++){
                if(a[i][j]!=0){
                    rm[temp][0]=i;
                     rm[temp][1]=j;
                     rm[temp][2]=a[i][j];
                     temp++;}
        }}
        printf("Triplet matrix is :\n");
        for(i=0;i<temp;i++){
            for(j=0;j<3;j++){
                printf("%d\t",rm[i][j]);}
                printf("\n");}
    }
 }