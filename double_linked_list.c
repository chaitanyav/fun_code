#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;
  struct Node *previous;
  struct Node *next;
};


void insert(struct Node **headRef, int data, int position) {
  struct Node *current, *previous, *newNode;
  int count = 0;

  newNode = malloc(sizeof(struct Node));

  if(newNode == NULL) {
    printf("Memory could not be allocated\n");
    return;
  }

  current = *headRef;
  newNode->data = data;

  if(position == 1) {
    if(current == NULL) {
      newNode->previous = NULL;
      newNode->next = NULL;
      *headRef = newNode;
      return;
    }

    newNode->previous = NULL;
    newNode->next = current;
    current->previous = newNode;
    *headRef = newNode;

  } else {

    while((current != NULL) && (count < position - 1)) {
      count++;
      previous = current;
      current = current->next;
    }

    if(current == NULL) {
      previous->next = newNode;
      newNode->next = NULL;
      newNode->previous = previous;
    } else {
      previous->next = newNode;
      newNode->next = current;
      newNode->previous = previous;
      current->previous = newNode;
    }
  }
}


void delete(struct Node **headRef, int position) {
  struct Node *current, *previous;
  int count = 0;
  current = *headRef;

  if(current == NULL) {
    printf("List is empty\n");
  }

  if(position == 1) {
    previous = current;
    current = current->next;
    current->previous = NULL;
    free(previous);
    *headRef = current;
  } else {
    while((current != NULL) && (count < position - 1)) {
      count++;
      previous = current;
      current = current->next;
    }

    if(current == NULL) {
      printf("Not a valid position %d\n", position);
      return;
    }


    previous->next = current->next;
    if(current->next != NULL) {
      (current->next)->previous = previous;
    }
    free(current);
  }
}

void deleteList(struct Node **headRef) {
  struct Node *auxillaryNode, *iterator;
  iterator = *headRef;

  while(iterator != NULL) {
    auxillaryNode = iterator;
    iterator = iterator->next;
    free(auxillaryNode);
  }

  *headRef = NULL;
}

void printList(struct Node *headRef) {
  struct Node *iterator;
  printf(" Head ");

  iterator = headRef;
  while(iterator != NULL) {
    printf(" %d ", iterator->data);
    iterator = iterator->next;
  }

  printf(" Tail ");
}


int length(struct Node *headRef) {
  struct Node *iterator;
  int count = 0;
  iterator = headRef;

  while(iterator != NULL) {
    count++;
    iterator = iterator->next;
  }
  return count;
}

int main() {
  struct Node *head = NULL;
  insert(&head, 5, 1);
  insert(&head, 2, 1);
  insert(&head, 1, 1);
  insert(&head, 3, 3);
  insert(&head, 4, 4);
  insert(&head, 6, 6);
  insert(&head, 0, 1);
  insert(&head, 7, 8);
  delete(&head, 1);
  delete(&head, 7);
  delete(&head, 3);
  delete(&head, 6);
  deleteList(&head);

  printf("Length is %d\n", length(head));
  printList(head);
  return 0;
}
