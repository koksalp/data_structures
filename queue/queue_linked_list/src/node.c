#include <stdio.h>
#include <stdlib.h>
#include "../include/node.h"

Node *create_node(int number) {
  Node *new_node = (Node *)malloc(sizeof(Node));
  new_node->number = number;
  new_node->next = NULL;

  return new_node;
}

void print_node(Node *node) {
  if (node == NULL) {
    printf("Node is NULL\n");
    return;
  }

  printf("Node -> number: %d | next: ", node->number);
  if (node->next) {
    printf("%d\n", node->next->number);
  } else {
    printf("NULL\n");
  }
}
