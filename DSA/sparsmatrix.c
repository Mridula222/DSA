#include<stdio.h>
int main(){
    int triplet[50][3],colmajor[50][3];
    int i,j,row,col,nz,temp;
    printf("enter the non zero elements\n");
    scanf("%d",&triplet[i][j]);

    printf("enter the triplet matrix\n");
    for(i=0;i<nz+1;i++){
        for(j=0;j<3;j++){
            scanf("%d",&triplet[i][j]);
        }
    }
    printf("triplet matrix is\n");
    for(i=0;i<nz+1;i++){
        for(j=0;j<3;j++){
            printf("%d\t",triplet[i][j]);
        }
        printf("\n");
    }
    row=triplet[0][0];
    col=triplet[0][1];
    colmajor[0][0]=j;
    colmajor[0][1]=triplet[i][0];
    colmajor[0][2]=triplet[i][2];
    for(i=0;i<)

}