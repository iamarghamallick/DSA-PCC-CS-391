// Tower of Hanoi

#include <stdio.h>
void towerOfHanoi(int n, int start, int stop, int temp)
{
    if (n > 0)
    {
        towerOfHanoi(n - 1, start, temp, stop);
        printf("Move Disk %d from Tower %d -> %d\n", n, start, stop);
        towerOfHanoi(n - 1, temp, stop, start);
    }
}
int main()
{
    int n;
    printf("Enter the number of Disks: ");
    scanf("%d", &n);
    towerOfHanoi(n, 1, 3, 2);
    return 0;
}