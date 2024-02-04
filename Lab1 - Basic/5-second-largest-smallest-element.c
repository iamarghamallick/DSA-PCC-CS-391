#include<stdio.h>
void bubbleSort(int arr[], int n) {
	for(int i=0; i<n-1; i++){
		for(int j=0; j<n-i-1; j++){
			if(arr[j] > arr[j+1]){
				int temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
			}
		}
	}
}
int main() {
        int n;
        printf("Enter array size: ");
        scanf("%d",&n);
        int arr[n];
        for(int i=0; i<n; i++) {
                printf("Enter number: ");
                scanf("%d",&arr[i]);
        }
	bubbleSort(arr, n);
	printf("Second largest: %d\n", arr[n-2]);
	printf("Second smallest: %d\n", arr[1]);
}
