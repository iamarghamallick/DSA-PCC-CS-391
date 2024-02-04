#include<stdio.h>
int main() {
        int n;
        printf("Enter array size: ");
        scanf("%d",&n);
        int arr[n];
        for(int i=0; i<n; i++) {
                printf("Enter number: ");
                scanf("%d",&arr[i]);
        }
	int small = arr[0];
	int large = arr[0];
	for(int i=0; i<n; i++) {
		small = arr[i] < small ? arr[i] : small;
		large = arr[i] > large ? arr[i] : large;
	}
	printf("Largest: %d\n", large);
	printf("Smallest: %d\n", small);
}
