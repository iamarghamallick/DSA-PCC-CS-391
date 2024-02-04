#include<stdio.h>
#include<stdlib.h>

struct Node {
	int data;
	struct Node *next;
};

struct Node* createSLL(int value) {
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->data = value;
	newNode->next = NULL;
	return newNode;
}

void addAtBeginning(struct Node **head, int value) {
	struct Node* newNode = createSLL(value);
	newNode->next = *head;
	*head = newNode;
}

void addAtEnd(struct Node **head, int value) {
	struct Node* newNode = createSLL(value);
	struct Node* curr = *head;
	while(curr->next != NULL) {
		curr = curr->next;
	}
	curr->next = newNode;
	newNode->next = NULL;
}

void addAtIntermediate(struct Node *prevNode, int value) {
	if(prevNode == NULL) {
		printf("Cannot add!! Previous node is NULL\n");
		return;
	}
	struct Node *newNode = createSLL(value);
	newNode->next = prevNode->next;
	prevNode->next = newNode;
}

void displaySLL(struct Node* head) {
	struct Node* curr = head;
	while(curr != NULL) {
		printf("%d -> ", curr->data);
		curr = curr->next;
	}
	printf("NULL\n");
}

int main() {
	struct Node* head = NULL;
	int choise, value, prevValue;
	do {
		printf("Enter your choise\n 1. Add At Beginning\t 2. Add At End\t 3. Display SLL\t 4. Add At Intermediate 0. Exit\n");
		scanf("%d", &choise);
		switch(choise) {
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
				scanf("%d",&prevValue);
				struct Node *curr = head;
				while(curr->data != prevValue) {
					curr = curr->next;
				}
				struct Node *prevNode = curr;
				addAtIntermediate(prevNode, value);
				break;
			default:
				printf("Invalid Choise! Try Again.\n");
				break;
		}
	} while (choise != 0);
}




