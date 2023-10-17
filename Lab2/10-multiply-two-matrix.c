#include <stdio.h>
int main()
{
    // input first matrix
    int m1, n1;
    printf("Enter number of rows: ");
    scanf("%d", &m1);
    printf("Enter number of cols: ");
    scanf("%d", &n1);
    int arr1[m1][n1];
    for (int i = 0; i < m1; i++)
    {
        for (int j = 0; j < n1; j++)
        {
            printf("Enter number for arr1[%d][%d]: ", i, j);
            scanf("%d", &arr1[i][j]);
        }
    }
    // input second matrix
    int m2, n2;
    printf("Enter number of rows: ");
    scanf("%d", &m2);
    printf("Enter number of cols: ");
    scanf("%d", &n2);
    int arr2[m2][n2];
    for (int i = 0; i < m2; i++)
    {
        for (int j = 0; j < n2; j++)
        {
            printf("Enter number for arr1[%d][%d]: ", i, j);
            scanf("%d", &arr2[i][j]);
        }
    }
    if (n2 == m1)
    {
        // do multiplication
        int mulArr[m1][n2];
        for (int i = 0; i < m1; i++)
        {
            for (int j = 0; j < n2; j++)
            {
                mulArr[i][j] = 0;
                for (int k = 0; k < m1; k++)
                {
                    mulArr[i][j] += arr1[i][k] * arr2[k][j];
                }
            }
        }
        // print the matrix
        printf("The multiplication is as follows\n");
        for (int i = 0; i < m1; i++)
        {
            for (int j = 0; j < n2; j++)
            {
                printf("%d ", mulArr[i][j]);
            }
            printf("\n");
        }
    }
    else
    {
        printf("Multiplication Not Possible.\n");
    }
}