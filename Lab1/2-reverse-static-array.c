#include <stdio.h>
void printArray(int arr[], int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d, ", arr[i]);
	}
	printf("\n");
}

int main()
{
	int n;
	printf("Enter array size: ");
	scanf("%d", &n);
	int arr[n];
	for (int i = 0; i < n; i++)
	{
		printf("Enter number: ");
		scanf("%d", &arr[i]);
	}
	printArray(arr, n);
	for (int i = 0; i < n / 2; i++)
	{
		int temp = arr[i];
		arr[i] = arr[n - i - 1];
		arr[n - i - 1] = temp;
	}
	printArray(arr, n);
}
