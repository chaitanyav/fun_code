#include <stdio.h>
#include <stdlib.h>

struct Node {
	int data;
	struct Node *next;
};

struct Queue {
	struct Node *front;
	struct Node *rear;
};

struct Queue* createQueue() {
	struct Queue *queue = (struct Queue *)malloc(sizeof(struct Queue));

	if(queue == NULL) {
		printf("Memory could not allocated for Queue\n");
		return NULL;
	} else {
		queue->front = NULL;
		queue->rear = NULL;
		return queue;
	}
}

void enqueue(struct Queue *queue, int data) {
	struct Node *newNode;

	if(queue == NULL) {
		printf("Queue does not exist\n");
	} else {
		newNode = (struct Node *)malloc(sizeof(struct Node));

		if(newNode == NULL) {
			printf("Memory could not be allocated for the Node\n");
			return;
		}

		newNode->data = data;
		newNode->next = NULL;

		if(queue->rear == NULL) {
			queue->rear = newNode;
		} else {
			queue->rear->next= newNode;
			queue->rear = newNode;
		}

		if(queue->front == NULL) {
			queue->front = queue->rear;
		}
		printf("Enqueued %d into Queue\n", newNode->data);
	}
}

void dequeue(struct Queue *queue) {
	struct Node *temp;

	if(queue == NULL) {
		printf("Queue does not exist\n");
	} else {
		if(queue->front == NULL) {
			printf("Queue is empty\n");
		} else {
			temp = queue->front;
			queue->front = queue->front->next;
			printf("Dequeued %d from Queue\n", temp->data);
			free(temp);
		}
	}
}

void empty(struct Queue *queue) {
	struct Node *temp;
	if(queue == NULL) {
		printf("Queue does not exist\n");
	} else {
		if(queue->front == NULL) {
			printf("Queue is already empty\n");
		} else {

			while(queue->front != NULL) {
				temp = queue->front;
				printf("Item %d removed from Queue\n", temp->data);
				queue->front = queue->front->next;
				free(temp);
			}

			queue->front = NULL;
			queue->rear = NULL;
		}
	}
}

void destroyQueue(struct Queue **queue) {
	if(*queue == NULL) {
		printf("Queue does not exist\n");
	} else {
		if((*queue)->front == NULL) {
			free(*queue);
			*queue = NULL;
		} else {
			printf("Queue is not empty\n");
		}
	}
}

void print(struct Queue *queue) {
	struct Node *temp;

	if(queue == NULL) {
		printf("Queue does not exist\n");
	} else {
		if(queue->front == NULL) {
			printf("Queue is empty\n");
		} else {
			temp = queue->front;

			printf("\n Front ");
			while(temp != NULL) {
				printf(" %d ", temp->data);
				temp = temp->next;
			}

			printf(" Rear \n");
		}
	}
}

int main() {
	struct Queue *queue = createQueue();
	enqueue(queue, 1);
	enqueue(queue, 2);
	enqueue(queue, 3);
	enqueue(queue, 4);
	dequeue(queue);
	print(queue);
	empty(queue);
	print(queue);
	empty(queue);
	dequeue(queue);
	destroyQueue(&queue);
	enqueue(queue, 1);
	dequeue(queue);
	print(queue);
    empty(queue);
	queue = createQueue();
	enqueue(queue, 1);
	dequeue(queue);
	print(queue);
	return 0;
}