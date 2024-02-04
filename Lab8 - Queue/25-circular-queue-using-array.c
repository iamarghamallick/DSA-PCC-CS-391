#include <stdio.h>
#include <stdlib.h>
#define MAX 5

int q[MAX];
int front = -1;
int rear = -1;

int isEmpty()
{
    return front == -1;
}

int isFull()
{
    return (front == 0 && rear == MAX - 1) || (front == rear + 1);
}

void enqueue(int data)
{
    if (isFull())
    {
        printf("Overflow\n");
        return;
    }
    if (front == -1)
        front = 0;
    rear = (rear + 1) % MAX;
    q[rear] = data;
}

int dequeue()
{
    if (isEmpty())
    {
        printf("Underflow\n");
        exit(0);
    }
    if (front == rear)
    {
        int temp = q[front];
        front = rear = -1;
        return temp;
    }
    int temp = q[front];
    front = (front + 1) % MAX;
    return temp;
}

void display()
{
    if (isEmpty())
    {
        printf("List is Empty!\n");
        exit(0);
    }
    for (int i = front; i != rear; i = (i + 1) % MAX)
    {
        printf("%d\t", q[i]);
    }
    printf("%d\n", q[rear]);
}

int main()
{
    enqueue(10);
    display();
    enqueue(20);
    enqueue(30);
    enqueue(40);
    display();
    dequeue();
    display();
    enqueue(50);
    display();
    return 0;
}