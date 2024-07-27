#include<stdio.h>
int main(){
    int sparse[30][30],row,col,i,j,nzero=0,temp=1;int triplet[30][30];
    printf("enter total rows");
    scanf("%d",&row);
    printf("enter total columns");
    scanf("%d",&col);
    //input for sparse
    for(i=0;i<row;i++){
        for(j=0;j<col;j++){
            printf("enter value");
            scanf("%d",&sparse[i][j]);
        }
    }
    //display
    for(i=0;i<row;i++){
        for(j=0;j<col;j++){
            printf("%d",sparse[i][j]);
        }
    }
    //count total nonzero values
    for(i=0;i<row;i++){
        for(j=0;j<col;j++){
            if(sparse[i][j]!=0){
                nzero++;
            }
        }
    }
    //convert to triplet matrix
     triplet[0][0]=row;
     triplet[0][1]=col;
     triplet[0][2]=nzero;

    for(i=0;i<row;i++){
        for(j=0;j<col;j++){
            if(sparse[i][j]!=0){
                triplet[temp][0]=i;
                triplet[temp][1]=j;
                triplet[temp][2]=sparse[i][j];
                temp++;
            }
        }
    }
    printf("values of triplet matrix are");
    for(i=0;i<nzero+1;i++){
        for(j=0;j<3;j++){
            printf("%d",triplet[i][j]);
        }
        printf("\n");
    }
}