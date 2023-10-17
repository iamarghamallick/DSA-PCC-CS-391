#include <stdio.h>
#define MAX 100

void transposeSparseMatrix(int original[MAX][3], int transpose[MAX][3], int rows, int cols)
{
    int count[MAX];
    int startPos[MAX];
    for (int i = 0; i < cols; i++)
        count[i] = 0;
    for (int i = 0; i < rows; i++)
        count[original[i][1]]++;
    startPos[0] = 0;
    for (int i = 1; i < cols; i++)
        startPos[i] = startPos[i - 1] + count[i - 1];
    for (int i = 0; i < rows; i++)
    {
        int j = original[i][1];
        int pos = startPos[j];
        transpose[pos][0] = original[i][1];
        transpose[pos][1] = original[i][0];
        transpose[pos][2] = original[i][2];
        startPos[j]++;
    }
}

void printSparseMatrix(int matrix[MAX][3], int rows)
{
    printf("Sparse Matrix:\n");
    for (int i = 0; i < rows; i++)
        printf("%d %d %d\n", matrix[i][0], matrix[i][1], matrix[i][2]);
}

int main()
{
    int originalMatrix[MAX][3];
    int transposeMatrix[MAX][3];
    int rows, cols, numElements;

    printf("Enter the number of rows and columns: ");
    scanf("%d %d", &rows, &cols);

    printf("Enter the number of non-zero elements: ");
    scanf("%d", &numElements);

    printf("Enter the non-zero elements (row, column, value):\n");
    for (int i = 0; i < numElements; i++)
        scanf("%d %d %d", &originalMatrix[i][0], &originalMatrix[i][1], &originalMatrix[i][2]);

    printf("Original Sparse Matrix:\n");
    printSparseMatrix(originalMatrix, numElements);

    transposeSparseMatrix(originalMatrix, transposeMatrix, rows, cols);

    printf("Transpose of the Sparse Matrix:\n");
    printSparseMatrix(transposeMatrix, numElements);

    return 0;
}
