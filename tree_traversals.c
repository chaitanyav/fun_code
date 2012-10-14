#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
  int data;
  struct TreeNode *left;
  struct TreeNode *right;
};

/* Queue for storing TreeNode */
struct Queue {
  struct Node *front;
  struct Node *rear;
};

struct Node {
  struct TreeNode *treeNode;
  struct Node *next;
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

void enqueue(struct Queue *queue, struct TreeNode *treeNode) {
	struct Node *newNode;

	if(queue == NULL) {
		printf("Queue does not exist\n");
	} else {
		newNode = (struct Node *)malloc(sizeof(struct Node));

		if(newNode == NULL) {
			printf("Memory could not be allocated for the Node\n");
			return;
		}

		newNode->treeNode = treeNode;
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
	}
}

struct TreeNode* dequeue(struct Queue *queue) {
	struct TreeNode *treeNode;
        struct Node *temp;

	if(queue == NULL) {
		printf("Queue does not exist\n");
	} else {
		if(queue->front == NULL) {
			printf("Queue is empty\n");
		} else {
			temp = queue->front;
                        treeNode = temp->treeNode;
			queue->front = queue->front->next;
                        free(temp);
			return treeNode;
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

/*
 *           1
 *          / \
 *         2   3
 *        /\   /\
 *       4  5  6 7
 *
 *       preorder traversal - Root, Left, Right
 *       Inorder traversal - Left, Root, Right
 *       Postorder traversal- Left, Right, Root
 */

void preOrderTraversal(struct TreeNode *root) {
  if(root != NULL) {
    printf(" %d ", root->data);
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
  }
}

void inOrderTraversal(struct TreeNode *root) {
  if(root != NULL) {
    inOrderTraversal(root->left);
    printf(" %d ", root->data);
    inOrderTraversal(root->right);
  }
}

void postOrderTraversal(struct TreeNode *root) {
  if(root != NULL) {
    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    printf(" %d ", root->data);
  }
}

int main() {

  // create the tree
  struct TreeNode *root = NULL;
  root = (struct TreeNode *)malloc(sizeof(struct TreeNode));
  root->data = 1;

  root->left = (struct TreeNode *)malloc(sizeof(struct TreeNode));
  (root->left)->data = 2;
  (root->left)->right = NULL;

  (root->left)->left = (struct TreeNode *)malloc(sizeof(struct TreeNode));
  ((root->left)->left)->data = 4;
  ((root->left)->left)->left = NULL;
  ((root->left)->left)->right = NULL;

  (root->left)->right = (struct TreeNode *)malloc(sizeof(struct TreeNode));
  ((root->left)->right)->data = 5;
  ((root->left)->right)->left = NULL;
  ((root->left)->right)->right = NULL;

  (root->right) = (struct TreeNode *)malloc(sizeof(struct TreeNode));
  (root->right)->data = 3;
  (root->right)->right = NULL;

  (root->right)->left = (struct TreeNode *)malloc(sizeof(struct TreeNode));
  ((root->right)->left)->data = 6;
  ((root->right)->left)->left = NULL;
  ((root->right)->left)->right = NULL;

  (root->right)->right = (struct TreeNode *)malloc(sizeof(struct TreeNode));
  ((root->right)->right)->data = 7;
  ((root->right)->right)->left = NULL;
  ((root->right)->right)->right = NULL;


  printf("     1   \n");
  printf("   /   \\  \n");
  printf("  2     3   \n");
  printf(" /  \\  / \\ \n");
  printf("4   5  6  7 \n");

  printf("\nPreOrder Traversal\n");
  preOrderTraversal(root);
  printf("\n");

  printf("InOrder Traversal\n");
  inOrderTraversal(root);
  printf("\n");

  printf("PostOrder Traversal\n");
  postOrderTraversal(root);
  printf("\n");

  printf("LevelOrder Traversal\n");
  struct TreeNode *temp = NULL;
  struct Queue *queue = createQueue();
  enqueue(queue, root);

  while(queue->front != NULL) {
    temp = dequeue(queue);
    printf(" %d ", temp->data);

    if(temp->left != NULL) {
      enqueue(queue, temp->left);
    }

    if(temp->right != NULL) {
      enqueue(queue, temp->right);
    }
  }

  printf("\n");
  destroyQueue(&queue);

  return 0;
}
