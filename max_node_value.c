#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct TreeNode {
  int data;
  struct TreeNode *left;
  struct TreeNode *right;
};

/*
 *           1
 *          / \
 *         2   3
 *        /\   /\
 *       4  5  6 7
 */

int findMax(struct TreeNode *root) {
  int root_val, left_val, right_val, max;
  max = INT_MIN;

  if(root != NULL) {
    root_val = root->data;
    left_val = findMax(root->left);
    right_val = findMax(root->right);

    max = (left_val > right_val) ? left_val : right_val;
    if(max < root_val) {
      max = root_val;
    }

  }

  return max;
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

  printf("\n %d is the max node value\n", findMax(root));
  return 0;
}
