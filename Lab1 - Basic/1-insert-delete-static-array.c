#include <stdio.h>
void printArray(int arr[], int size)
{
	for (int i = 0; i < size; i++)
	{
		printf("%d, ", arr[i]);
	}
	printf("\n");
}
int main()
{
	int arr[100], element, index, choise, next = 1, size = 0;
	do
	{
		printf("1. Add\t2. Delete\t0. Exit\n");
		scanf("%d", &choise);
		switch (choise)
		{
		case 1:
			printf("Enter the element: ");
			scanf("%d", &element);
			printf("Enter index: ");
			scanf("%d", &index);
			for (int i = size - 1; i >= index; i--)
			{
				arr[i + 1] = arr[i];
			}
			arr[index] = element;
			size++;
			printArray(arr, size);
			break;
		case 2:
			printf("Enter index: ");
			scanf("%d", &index);
			for (int i = index; i < size; i++)
			{
				arr[i] = arr[i + 1];
			}
			size--;
			printArray(arr, size);
			break;
		case 0:
			next = 0;
			break;
		default:
			printf("Invalid Input!\n");
		}
	} while (next == 1);
}
