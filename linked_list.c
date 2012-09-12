#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;
  struct Node *next;
};

void insert(struct Node **head, int data, int position) {
  struct Node *previous, *current, *newNode;
  int count = 0;

  newNode = malloc(sizeof(struct Node));

  if(newNode == NULL) {
    printf("Memory could be allocated\n");
  }

  newNode->data = data;
  current = *head;

  if(position == 1) {
    newNode->next = *head;
    *head = newNode;
  } else {

    while((current != NULL) && (count < position - 1)) {
      count++;
      previous = current;
      current = current->next;
    }

    if(current == NULL) {
      previous->next = newNode;
      newNode->next = NULL;
    } else {
      previous->next = newNode;
      newNode->next = current;
    }
  }
}

void delete(struct Node **head, int position) {
  struct Node *previous, *current;
  int count = 0;

  if(*head == NULL) {
    printf("List is empty\n");
    return;
  }

  current = *head;
  if(position == 1) {
    *head = current->next;
    free(current);
    return;
  } else {
    while((current != NULL) && (count < position - 1)) {
      count++;
      previous = current;
      current = current->next;
    }

    if(current == NULL) {
      printf("Position does not exist\n");
    } else {
      previous->next = current->next;
      free(current);
    }
  }

}

int length(struct Node *head) {
  struct Node *current = head;
  int count = 0;

  while(current != NULL) {
    count++;
    current = current->next;
  }

  return count;
}

void print(struct Node *head) {
  struct Node *current = head;

  printf(" Head ");
  while(current != NULL) {
    printf(" %d ", current->data);
    current = current->next;
  }
  printf(" Tail \n");
}

void deleteList(struct Node **head) {
  struct Node *temp, *current;
  current = *head;
  while(current != NULL) {
    temp = current;
    current = current->next;
    free(temp);
  }

  *head = NULL;
}

int main() {
  struct Node *head = NULL;

  insert(&head, 1, 1);
  insert(&head, 2, 1);
  insert(&head, 3, 1);
  insert(&head, 4, 2);
  insert(&head, 5, 2);
  insert(&head, 6, 6);
  delete(&head, 1);
  delete(&head, 3);
  delete(&head, 4);
  delete(&head, 6);

  print(head);
  printf("Length of the list is %d\n", length(head));
  deleteList(&head);

  print(head);
  printf("Length of the list is %d\n", length(head));

  return 0;
}
