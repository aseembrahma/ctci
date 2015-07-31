#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int value;
  struct Node * next;
} Node;

int list_append(Node ** head, int value) {
  Node * new_node = (Node *) malloc(sizeof(Node));
  if (NULL == new_node)
    return -1;
  new_node->value = value;
  new_node->next = NULL;

  Node ** node_ptr = NULL;

  if (NULL == *head) {
    node_ptr = head;
  }
  else {
    Node * node = *head;
    while (node->next != NULL) {
      node = node->next;
    }
    node_ptr = &(node->next);
  }
  *node_ptr = new_node;

  return 0;
}

void print_list(Node * head) {
  printf("List values: [ ");
  while (NULL != head) {
    printf("%d ", head->value);
    head = head->next;
  }
  printf("]\n");
}

Node * reverse_list(Node * head) {
  if (NULL == head || NULL == head->next) {
    return head;
  }

  Node * new_head = reverse_list(head->next);

  head->next->next = head;
  head->next = NULL;

  return new_head;
}

int main() {
  Node * aList = NULL;

  int retval = 
       list_append(&aList, 1)
    || list_append(&aList, 2)
    || list_append(&aList, 3)
    || list_append(&aList, 4)
    || list_append(&aList, 5)
    || list_append(&aList, 6)
    ;
  if (retval) {
    printf("Failed to populate list\n");
    return -1;
  }
  print_list(aList);

  aList = reverse_list(aList);
  print_list(aList);
}

