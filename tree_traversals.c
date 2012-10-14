#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;
  struct Node *left;
  struct Node *right;
};

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

void preOrderTraversal(struct Node *root) {
  if(root != NULL) {
    printf(" %d ", root->data);
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
  }
}

void inOrderTraversal(struct Node *root) {
  if(root != NULL) {
    inOrderTraversal(root->left);
    printf(" %d ", root->data);
    inOrderTraversal(root->right);
  }
}

void postOrderTraversal(struct Node *root) {
  if(root != NULL) {
    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    printf(" %d ", root->data);
  }
}

int main() {

  // create the tree
  struct Node *root = NULL;
  root = (struct Node *)malloc(sizeof(struct Node));
  root->data = 1;

  root->left = (struct Node *)malloc(sizeof(struct Node));
  (root->left)->data = 2;
  (root->left)->right = NULL;

  (root->left)->left = (struct Node *)malloc(sizeof(struct Node));
  ((root->left)->left)->data = 4;
  ((root->left)->left)->left = NULL;
  ((root->left)->left)->right = NULL;

  (root->left)->right = (struct Node *)malloc(sizeof(struct Node));
  ((root->left)->right)->data = 5;
  ((root->left)->right)->left = NULL;
  ((root->left)->right)->right = NULL;

  (root->right) = (struct Node *)malloc(sizeof(struct Node));
  (root->right)->data = 3;
  (root->right)->right = NULL;

  (root->right)->left = (struct Node *)malloc(sizeof(struct Node));
  ((root->right)->left)->data = 6;
  ((root->right)->left)->left = NULL;
  ((root->right)->left)->right = NULL;

  (root->right)->right = (struct Node *)malloc(sizeof(struct Node));
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

  return 0;
}
