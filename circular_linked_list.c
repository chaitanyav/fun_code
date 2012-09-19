#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int data;
	struct Node *next;
};


void insertAtEnd(struct Node **headRef, int data) {
	struct Node *current = *headRef;
	struct Node *newNode = (struct Node *) malloc(sizeof(struct Node));

	if(newNode == NULL) {
		printf("Memory could not be allocated\n");
		return;
	}

	newNode->data = data;
	newNode->next = newNode;

	if(*headRef == NULL) {
		*headRef = newNode;
	} else {

		while(current->next != *headRef) {
			current = current->next;
		}

		newNode->next = *headRef;
		current->next = newNode;
	}
}

void insertAtBegin(struct Node **headRef, int data) {
	struct Node *current = *headRef;
	struct Node *newNode = (struct Node *) malloc(sizeof(struct Node));

	if(newNode == NULL) {
		printf("Memory could not be allocated\n");
		return;
	}

	newNode->data = data;
	newNode->next = newNode;

	if(*headRef == NULL) {
		*headRef = newNode;
	} else {

		while(current->next != *headRef) {
			current = current->next;
		}

		newNode->next = *headRef;
		current->next = newNode;
		*headRef = newNode;
	}
}

void deleteAtBegin(struct Node **headRef) {
	struct Node *temp = *headRef;
	struct Node *current = *headRef;

	if(*headRef == NULL) {
		printf("List is empty\n");
		return;
	} else {
		while(current->next != *headRef) {
			current = current->next;
		}

		current->next = (*headRef)->next;

		if(*headRef != (*headRef)->next) {
			*headRef = (*headRef)->next;
		} else {
			*headRef = NULL;
		}
		free(temp);
	}
}

void deleteAtEnd(struct Node **headRef) {
	struct Node *temp = *headRef;
	struct Node *current = *headRef;

	if(*headRef == NULL) {
		printf("List is empty\n");
	} else {

		while(current->next != *headRef) {
			temp = current;
			current = current->next;
		}

		temp->next = *headRef;

		if(temp == current) {
			*headRef = NULL;
		}

		free(current);
	}
}

void printList(struct Node *headRef) {
	struct Node *current = headRef;

	printf(" Head ");
	if(headRef != NULL) {
		while(current->next != headRef) {
			printf(" %d ", current->data);
			current = current->next;
		}

		printf(" %d ", current->data);
	}
	printf(" Tail \n");

}

int length(struct Node *headRef) {
	struct Node *current;
	int count = 0;

	current = headRef;

	if(headRef != NULL) {
		while(current->next != headRef) {
			count++;
			current = current->next;
		}
		count++;
	}

	return count;
}

int main() {
	struct Node *head = NULL;
	insertAtBegin(&head, 1);
	insertAtBegin(&head, 0);
	insertAtEnd(&head, 2);
	insertAtEnd(&head, 3);
	insertAtEnd(&head, 4);
	deleteAtBegin(&head);
	deleteAtBegin(&head);
	deleteAtBegin(&head);
	deleteAtEnd(&head);
	printf("Length of the list is %d\n", length(head));
	printList(head);
	return 0;
}