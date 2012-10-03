#include <stdio.h>
#include <stdlib.h>

struct Node {
	int data;
	struct Node *next;
};

struct Stack {
	struct Node *head;
};

struct Stack* createStack() {
	struct Stack *stack = (struct Stack *)malloc(sizeof(struct Stack));

	if(stack == NULL) {
		printf("Memory could not be allocated for Stack\n");
		return NULL;
	}

	stack->head = NULL;
	return stack;
}

void push(struct Stack *stack, int value) {
	struct Node *newNode;

	if(stack == NULL) {
		printf("Stack does not exist\n");
	} else {
		newNode = (struct Node *) malloc(sizeof(struct Node));
		if(newNode == NULL) {
			printf("Memory could not be allocated to new Node\n");
			return;
		}

		newNode->data = value;

		if(stack-> head == NULL) {
			stack->head = newNode;
			newNode->next = NULL;
		} else {
			newNode->next = stack->head;
			stack->head = newNode;
		}
	}
}

void pop(struct Stack *stack) {
	struct Node *temp;

	if(stack == NULL) {
		printf("Stack does not exist\n");
	} else {
		if(stack->head == NULL) {
			printf("Stack is empty\n");
		} else {
			temp = stack->head;
			stack->head = stack->head->next;
			printf("\n%d popped from the stack\n", temp->data);
			free(temp);
		}
	}
}

void print(struct Stack *stack) {
	struct Node *current;

	if(stack == NULL) {
		printf("Stack does not exist\n");
	} else {

		current = stack->head;

		if(current == NULL) {
			printf("Stack is empty\n");
		} else {
			printf("Top ");
			while(current != NULL) {
				printf(" %d ", current->data);
				current = current->next;
			}
		}
	}
}

void empty(struct Stack *stack) {
	struct Node *current;
	struct Node *previous;


	if(stack == NULL) {
		printf("Stack does not exist\n");
	} else {
		current = stack->head;
		if(current == NULL) {
			printf("Stack is empty\n");
		} else {
			while(current != NULL) {
				previous = current;
				current = current->next;
				printf("Node with data %d deleted\n", previous->data);
				free(previous);
			}
			stack->head = NULL;
		}
	}
}

void destroyStack(struct Stack **stack) {
	if(*stack == NULL) {
		printf("Stack does not exist\n");
	}
	else {
		if((*stack)->head != NULL) {
			printf("Stack is not empty\n");
		} else {
			free(*stack);
			*stack = NULL;
		}
	}
}

int main() {
	struct Stack *stack = NULL;

	pop(stack);
	stack = createStack();
	pop(stack);
	push(stack, 1);
	push(stack, 2);
	push(stack, 3);
	print(stack);
	pop(stack);
	print(stack);
	pop(stack);
	print(stack);
	pop(stack);
	print(stack);
	push(stack, 4);
	push(stack, 5);
	push(stack, 6);
	empty(stack);
	print(stack);
	empty(stack);
	push(stack, 7);
	push(stack, 8);
	push(stack, 9);
	empty(stack);
	destroyStack(&stack);
	print(stack);
	push(stack, 10);
	pop(stack);
	empty(stack);
	destroyStack(&stack);
	stack = createStack();
	push(stack, 1);
	push(stack, 2);
	push(stack, 3);
	print(stack);
	pop(stack);
	print(stack);
	pop(stack);
	print(stack);
	pop(stack);
	pop(stack);
	return 0;
}
