#include<stdio.h>
#include<stdlib.h>

void accept_matrix(int**matrix, int m, int n)
{
    printf("enter the elements of the matrix(%d x %d):\n", m,n);
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            printf("element[%d][%d]:", i+1,j+1);
            scanf("%d", &matrix[i][j]);
        }
    }
}
 void display_matrix(int**matrix, int m, int n)
 {
    printf("matrix (%d x %d): \n ", m,n);
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    } 
 }

 int main()
 {
    int**matrix;
    int m,n;

    printf("\nenter no. of rows");
    scanf("%d", &n);

    printf("\n enter no. of columns");
    scanf("%d", &m);

    matrix=(int**)malloc(m *sizeof(int *));
    for(int i=0;i<m;i++)
    {
        matrix[i]=(int *)malloc(n * sizeof(int));
    }

    accept_matrix(matrix, m, n);
    display_matrix(matrix, m ,n);

    for(int i=0;i<m;i++)
    {
        free(matrix[i]);
    }
    free(matrix);
    return 0;
 }