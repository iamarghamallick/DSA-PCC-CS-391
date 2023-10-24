#include <stdio.h>

void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int arr[], int low, int high)
{
    int pivot = arr[low]; // Choose the first element as the pivot
    int i = low;

    for (int j = low + 1; j <= high; j++)
    {
        // If the current element is smaller than the pivot
        if (arr[j] < pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }

    swap(&arr[low], &arr[i]);
    return i;
}

void quicksort(int arr[], int low, int high)
{
    if (low < high)
    {
        int partitionIndex = partition(arr, low, high);
        quicksort(arr, low, partitionIndex - 1);
        quicksort(arr, partitionIndex + 1, high);
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
    quicksort(arr, 0, n - 1);
    printArray(arr, n);

    return 0;
}