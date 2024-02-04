#include <stdio.h>
void linearSearch(int arr[], int n, int key)
{
	for (int i = 0; i < n; i++)
	{
		if (arr[i] == key)
		{
			printf("Element is present in the array\n");
			return;
		}
	}
	printf("Element is not present in the array!\n");
}
void RLinearSearch(int arr[], int n, int i, int key)
{
	if (i == n)
	{
		printf("Element is not present in the array!\n");
		return;
	}
	if (arr[i] == key)
	{
		printf("Element is present in the array\n");
		return;
	}
	else
		RLinearSearch(arr, n, i + 1, key);
}
void binarySearch(int arr[], int left, int right, int key)
{
	while (left <= right)
	{
		int mid = left + (right - 1) / 2;
		if (arr[mid] == key)
		{
			printf("Element is present in the array\n");
			return;
		}
		if (key > arr[mid])
			left = mid + 1;
		else
			right = mid - 1;
	}
	printf("Element is not present in the array!\n");
	return;
}
void RBinarySearch(int arr[], int left, int right, int key)
{
	if (left <= right)
	{
		int mid = left + (right - 1) / 2;
		if (key == arr[mid])
		{
			printf("Element is present in the array\n");
			return;
		}
		if (key < arr[mid])
			return RBinarySearch(arr, left, mid - 1, key);
		else
			return RBinarySearch(arr, mid + 1, right, key);
	}
	printf("Element is not present in the array!\n");
	return;
}
int main()
{
	int n, key;
	printf("Enter array size: ");
	scanf("%d", &n);
	int arr[n];
	for (int i = 0; i < n; i++)
	{
		printf("Enter number: ");
		scanf("%d", &arr[i]);
	}
	printf("Enter the element to search: ");
	scanf("%d", &key);
	// linearSearch(arr, n, key);
	// binarySearch(arr, 0, n-1, key);
	// RLinearSearch(arr, n, 0, key);
	RBinarySearch(arr, 0, n - 1, key);
}
