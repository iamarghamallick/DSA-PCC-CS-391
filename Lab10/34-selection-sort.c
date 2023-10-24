#include <stdio.h>

void selection(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int min = i;
        for (int j = i + 1; j < n; j++)
            min = arr[j] < arr[min] ? j : min;
        // swapping
        int temp = arr[min];
        arr[min] = arr[i];
        arr[i] = temp;
    }
}

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d\t", arr[i]);
    }
    printf("\n");
}

int main()
{
    int n = 10;
    int arr[] = {5, 8, 1, 10, 6, 3, 9, 2, 4, 7};

    printArray(arr, n);
    selection(arr, n);
    printArray(arr, n);

    return 0;
}