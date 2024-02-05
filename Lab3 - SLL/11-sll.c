#include <stdio.h>
#include <stdlib.h>

struct Node
{
	int data;
	struct Node *next;
};

struct Node *createSLL(int value)
{
	struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
	newNode->data = value;
	newNode->next = NULL;
	return newNode;
}

void addAtBeginning(struct Node **head, int value)
{
	struct Node *newNode = createSLL(value);
	newNode->next = *head;
	*head = newNode;
}

void addAtEnd(struct Node **head, int value)
{
	struct Node *newNode = createSLL(value);
	struct Node *curr = *head;
	while (curr->next != NULL)
	{
		curr = curr->next;
	}
	curr->next = newNode;
	newNode->next = NULL;
}

void addAtIntermediate(struct Node *prevNode, int value)
{
	if (prevNode == NULL)
	{
		printf("Cannot add!! Previous node is NULL\n");
		return;
	}
	struct Node *newNode = createSLL(value);
	newNode->next = prevNode->next;
	prevNode->next = newNode;
}

void deleteFromBeginning(struct Node **head)
{
	if (*head == NULL || (*head)->next == NULL)
	{
		*head = NULL;
		return;
	}

	*head = (*head)->next;
}

void deleteFromEnd(struct Node **head)
{
	if (*head == NULL || (*head)->next == NULL)
	{
		*head = NULL;
		return;
	}

	struct Node *temp = *head;
	while (temp->next->next != NULL)
	{
		temp = (*head)->next;
	}

	struct Node *nodeToDelete = temp->next;
	temp->next = NULL;
	free(nodeToDelete);
}

void deleteFromIntermediate(struct Node **head, int value)
{
	struct Node *prev = *head;

	// Check if the head itself contains the value to be deleted
	if (prev != NULL && prev->data == value)
	{
		*head = prev->next;
		free(prev);
		return;
	}

	while (prev != NULL && prev->next != NULL)
	{
		if (prev->next->data != value)
		{
			prev = prev->next;
		}
		else
		{
			struct Node *nodeToDelete = prev->next;
			prev->next = prev->next->next;
			free(nodeToDelete);
			return; // Node found and deleted, exit the function
		}
	}
}

void displaySLL(struct Node *head)
{
	struct Node *curr = head;
	while (curr != NULL)
	{
		printf("%d -> ", curr->data);
		curr = curr->next;
	}
	printf("NULL\n");
}

int main()
{
	struct Node *head = NULL;
	int choise, value, prevValue;
	do
	{
		printf("Enter your choise\n 1. Add At Beginning\t 2. Add At End\t 3. Display SLL\t 4. Add At Intermediate\t 5. Delete from Beginning\t 6. Delete from End\t 7.Delete from Intermediate 0. Exit\n");
		scanf("%d", &choise);
		switch (choise)
		{
		case 1:
			printf("Enter the value: ");
			scanf("%d", &value);
			addAtBeginning(&head, value);
			break;
		case 2:
			printf("Enter the value: ");
			scanf("%d", &value);
			addAtEnd(&head, value);
			break;
		case 3:
			displaySLL(head);
			break;
		case 4:
			printf("Enter the value to be added: ");
			scanf("%d", &value);
			printf("Enter the value after which you want to add: ");
			scanf("%d", &prevValue);
			struct Node *curr = head;
			while (curr->data != prevValue)
			{
				curr = curr->next;
			}
			struct Node *prevNode = curr;
			addAtIntermediate(prevNode, value);
			break;
		case 5:
			deleteFromBeginning(&head);
			break;
		case 6:
			deleteFromEnd(&head);
			break;
		case 7:
			printf("Enter the value to be deleted: ");
			scanf("%d", &value);
			deleteFromIntermediate(&head, value);
			break;
		case 0:
			printf("Goodbye!\n");
			exit(0);
		default:
			printf("Invalid Choise! Try Again.\n");
			break;
		}
	} while (choise != 0);
}
