#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100
struct Deque
{
    int items[MAX_SIZE];
    int front, rear;
};
struct Deque *createDeque()
{
    struct Deque *deque = (struct Deque *)malloc(sizeof(struct Deque));
    deque->front = -1;
    deque->rear = -1;
    return deque;
}
int isEmpty(struct Deque *deque)
{
    return (deque->front == -1);
}
int isFull(struct Deque *deque)
{
    return ((deque->rear + 1) % MAX_SIZE == deque->front);
}
void insertFront(struct Deque *deque, int value)
{
    if (isFull(deque))
    {
        printf("Deque is full. Cannot insert at the front.\n");
        return;
    }
    if (isEmpty(deque))
    {
        deque->front = deque->rear = 0;
    }
    else
    {
        deque->front = (deque->front - 1 + MAX_SIZE) % MAX_SIZE;
    }
    deque->items[deque->front] = value;
    printf("%d inserted at the front of the deque.\n", value);
}
void insertRear(struct Deque *deque, int value)
{
    if (isFull(deque))
    {
        printf("Deque is full. Cannot insert at the rear.\n");
        return;
    }
    if (isEmpty(deque))
    {
        deque->front = deque->rear = 0;
    }
    else
    {
        deque->rear = (deque->rear + 1) % MAX_SIZE;
    }
    deque->items[deque->rear] = value;
    printf("%d inserted at the rear of the deque.\n", value);
}
int deleteFront(struct Deque *deque)
{
    if (isEmpty(deque))
    {
        printf("Deque is empty. Cannot delete from the front.\n");
        return -1;
    }
    int item = deque->items[deque->front];
    if (deque->front == deque->rear)
    {
        deque->front = deque->rear = -1;
    }
    else
    {
        deque->front = (deque->front + 1) % MAX_SIZE;
    }
    printf("%d deleted from the front of the deque.\n", item);
    return item;
}
int deleteRear(struct Deque *deque)
{
    if (isEmpty(deque))
    {
        printf("Deque is empty. Cannot delete from the rear.\n");
        return -1;
    }
    int item = deque->items[deque->rear];
    if (deque->front == deque->rear)
    {
        deque->front = deque->rear = -1;
    }
    else
    {
        deque->rear = (deque->rear - 1 + MAX_SIZE) % MAX_SIZE;
    }
    printf("%d deleted from the rear of the deque.\n", item);
    return item;
}
void display(struct Deque *deque)
{
    if (isEmpty(deque))
    {
        printf("Deque is empty.\n");
        return;
    }
    printf("Deque elements: ");
    int i = deque->front;
    while (1)
    {
        printf("%d ", deque->items[i]);
        if (i == deque->rear)
            break;
        i = (i + 1) % MAX_SIZE;
    }
    printf("\n");
}
int main()
{
    struct Deque *deque = createDeque();
    int choice, value;
    while (1)
    {
        printf("\nDeque Operations:\n");
        printf("1. Insert at Front\n");
        printf("2. Insert at Rear\n");
        printf("3. Delete from Front\n");
        printf("4. Delete from Rear\n");
        printf("5. Display\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter a value to insert at the front: ");
            scanf("%d", &value);
            insertFront(deque, value);
            break;
        case 2:
            printf("Enter a value to insert at the rear: ");
            scanf("%d", &value);
            insertRear(deque, value);
            break;
        case 3:
            deleteFront(deque);
            break;
        case 4:
            deleteRear(deque);
            break;
        case 5:
            display(deque);
            break;
        case 6:
            exit(0);
        default:
            printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}
