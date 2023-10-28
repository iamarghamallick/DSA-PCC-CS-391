#include <stdio.h>

void merge(int arr[], int mid, int low, int high)
{
    int i = low;
    int j = mid + 1;
    int k = low;
    int sortedArr[100];

    while (i <= mid && j <= high)
    {
        if (arr[i] < arr[j])
            sortedArr[k++] = arr[i++];
        else
            sortedArr[k++] = arr[j++];
    }

    while (i <= mid)
        sortedArr[k++] = arr[i++];

    while (j <= high)
        sortedArr[k++] = arr[j++];

    for (int i = low; i <= high; i++)
        arr[i] = sortedArr[i];
}

void mergesort(int arr[], int low, int high)
{
    if (low < high)
    {
        int mid = (low + high) / 2;
        mergesort(arr, low, mid);
        mergesort(arr, mid + 1, high);

        merge(arr, mid, low, high);
    }
}

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%d\t", arr[i]);

    printf("\n");
}

int main()
{
    int n = 10;
    int arr[] = {5, 8, 1, 10, 6, 3, 9, 2, 4, 7};

    printArray(arr, n);
    mergesort(arr, 0, n - 1);
    printArray(arr, n);

    return 0;
}