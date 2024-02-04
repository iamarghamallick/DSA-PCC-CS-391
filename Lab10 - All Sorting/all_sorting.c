#include <stdio.h>

void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

void bubble(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - 1 - i; j++)
            if (arr[j] > arr[j + 1])
                swap(&arr[j], &arr[j + 1]);
}

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

void selection(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int min = i;
        for (int j = i + 1; j < n; j++)
            min = arr[j] < arr[min] ? j : min;
        // swapping
        swap(&arr[min], &arr[i]);
    }
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
    {
        printf("%d\t", arr[i]);
    }
    printf("\n");
}

int main()
{
    int n = 10;
    int arr[] = {5, 8, 1, 10, 6, 3, 9, 2, 4, 7};

    printf("Before Sorting: \n");
    printArray(arr, n);

    printf("Sorted List (Using Bubble Sort): \n");
    bubble(arr, n);
    printArray(arr, n);

    printf("Sorted List (Using Intertion Sort): \n");
    insertion(arr, n);
    printArray(arr, n);

    printf("Sorted List (Using Selection Sort): \n");
    selection(arr, n);
    printArray(arr, n);

    printf("Sorted List (Using Quick Sort): \n");
    quicksort(arr, 0, n - 1);
    printArray(arr, n);

    printf("Sorted List (Using Merge Sort): \n");
    mergesort(arr, 0, n - 1);
    printArray(arr, n);

    return 0;
}