#include <stdio.h>
int main()
{
    int m, n;
    printf("Enter number of rows: ");
    scanf("%d", &m);
    printf("Enter number of cols: ");
    scanf("%d", &n);
    int arr[m][n];
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("Enter number for arr[%d][%d]: ", i, j);
            scanf("%d", &arr[i][j]);
        }
    }
    int isSparse = 0, nonZeroCount = 0, zeroCount = 0;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (arr[i][j] != 0)
                nonZeroCount++;
            else
                zeroCount++;
        }
    }
    if (zeroCount > nonZeroCount)
        isSparse = 1;
    if (isSparse == 1)
    {
        // represent it as 3 - tuple format
        int sparse[3][nonZeroCount], k = 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (arr[i][j] != 0)
                {
                    sparse[0][k] = i;
                    sparse[1][k] = j;
                    sparse[2][k] = arr[i][j];
                    k++;
                }
            }
        }
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < nonZeroCount; j++)
                printf("%d ", sparse[i][j]);
            printf("\n");
        }
    }
}