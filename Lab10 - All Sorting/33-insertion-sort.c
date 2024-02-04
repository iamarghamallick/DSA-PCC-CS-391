#include <stdio.h>

void insertion(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
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
    insertion(arr, n);
    printArray(arr, n);

    return 0;
}