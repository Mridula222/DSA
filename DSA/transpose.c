#include <stdio.h>
int main()
{
    int triplet[50][3], colmajor[50][3];
    int i, j, row, col, nz, temp = 1;

    printf("enter non zero values");
    scanf("%d", &nz);

    printf("enter the triplet matrix");
    for (i = 0; i < nz + 1; i++)
    {
        for (j = 0; j < 3; j++)
        {
            scanf("%d", &triplet[i][j]);
        }
    }
    printf("triplet matrix is\n");
    for (i = 0; i < nz + 1; i++)
    {
        for (j = 0; j < 3; j++)
        {
            printf("%d\t", triplet[i][j]);
        }
        printf("\n");
    }
    row = triplet[0][0];
    col = triplet[0][1];
    colmajor[0][0] = col;
    colmajor[0][1] = row;
    colmajor[0][2] = nz;
    for (j = 0; j <= col; j++)
    {
        for (i = 1; i < nz + 1; i++)
        {
            if (triplet[i][1] == j)
            {
                colmajor[temp][0] = j;
                colmajor[temp][1] = triplet[i][0];
                colmajor[temp][2] = triplet[i][2];
                temp++;
            }
        }
    }
    printf("transpose is");
    for (i = 0; i < nz + 1; i++)
    {
        for (j = 0; j < 3; j++)
        {
            printf("%d\t", colmajor[i][j]);
        }
        printf("\n");
    }
}