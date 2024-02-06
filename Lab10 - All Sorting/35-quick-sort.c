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
    int i = low + 1;
    int j = high;
    do
    {
        while (arr[i] <= pivot)
            i++;
        while (arr[j] > pivot)
            j--;
        if (i < j)
            swap(&arr[i], &arr[j]);
    } while (i < j);

    swap(&arr[low], &arr[j]);
    return j;
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