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

struct Queue* createQueue();
void enqueue(struct Queue *queue, int data);
void dequeue(struct Queue *queue);
void empty(struct Queue *queue);
void destroyQueue(struct Queue **queue);
void print(struct Queue *queue);
