#include <stdio.h>
#include <stdlib.h>
#define MAX 100

int q[MAX];
int front = -1;
int rear = -1;

int isEmpty()
{
    return front == -1 && rear == -1;
}

int isFull()
{
    return rear == MAX - 1;
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
    q[++rear] = data;
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
    int temp = q[front++];
    return temp;
}

void display()
{
    for (int i = front; i <= rear; i++)
    {
        printf("%d\t", q[i]);
    }
    printf("\n");
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