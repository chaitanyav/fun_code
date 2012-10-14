#include <stdio.h>
#include <stdlib.h>

struct CircularQueue {
	int front, rear;
	int size;
	int *buffer;
};


struct CircularQueue *createQueue(int size) {
	struct CircularQueue *queue = (struct CircularQueue *)malloc(sizeof(struct CircularQueue));

	if(queue == NULL) {
		printf("Memory could not allocated for CircularQueue\n");
		return NULL;
	} else {
		queue->size = size;
		queue->front = queue->rear = -1;
		queue->buffer = (int *)malloc(queue->size * sizeof(int));

		if(queue->buffer == NULL) {
			printf("Memory could not be allocated for the buffer\n");
			return NULL;
		} else {
			return queue;
		}
	}
}

int isQueueEmpty(struct CircularQueue *queue) {
	return (queue->front == -1);
}

int isQueueFull(struct CircularQueue * queue) {
	return(((queue->rear + 1) % queue->size) == queue->front);
}

int sizeOfQueue(struct CircularQueue *queue) {
	return ((queue->size - queue->front + queue->rear + 1) % queue->size);
}

void enqueue(struct CircularQueue *queue, int data) {

	if(queue == NULL) {
		printf("CircularQueue does not exist\n");
	} else {
		if(isQueueFull(queue)) {
			printf("CircularQueue is full\n");
		} else {
			queue->rear = (queue->rear + 1) % queue->size;
			queue->buffer[queue->rear] = data;
			printf("%d is Enqueued into CircularQueue\n", data);
			if(queue->front == -1) {
				queue->front = queue->rear;
			}
		}
	}
}

void dequeue(struct CircularQueue *queue) {
	if(queue == NULL) {
		printf("CircularQueue does not exist\n");
	} else {
		if(isQueueEmpty(queue)) {
			printf("CircularQueue is empty\n");
		} else {
			printf("%d is Dequeued from CircularQueue\n", queue->buffer[queue->front]);
			if(queue->front == queue->rear) {
				queue->front = queue->rear = -1;
			} else {
				queue->front = (queue->front + 1) % queue->size;
			}
		}
	}
}

void destroyQueue(struct CircularQueue **queue) {
	if(*queue) {
		if((*queue)->buffer) {
			free((*queue)->buffer);
		}
		free(*queue);
		*queue = NULL;
	}
}

void print(struct CircularQueue *queue) {
	int temp;
	if(queue == NULL) {
		printf("CircularQueue does not exist\n");
	} else {
		if(isQueueEmpty(queue)) {
			printf("CircularQueue is empty\n");
		} else {
			temp = queue->front;
			printf("\n Front ");
			for(temp; temp <= queue->rear; temp++) {
				printf(" %d ", queue->buffer[temp]);
			}
			printf(" Rear \n");
		}
	}
}

int main() {
	struct CircularQueue *queue = createQueue(5);
	dequeue(queue);
	enqueue(queue, 1);
	enqueue(queue, 2);
	enqueue(queue, 3);
	enqueue(queue, 4);
	enqueue(queue, 5);
	enqueue(queue, 6);
	print(queue);
	dequeue(queue);
	dequeue(queue);
	print(queue);
	dequeue(queue);
	dequeue(queue);
	dequeue(queue);
	dequeue(queue);
	print(queue);
	destroyQueue(&queue);
	enqueue(queue, 1);
	dequeue(queue);
	print(queue);
}