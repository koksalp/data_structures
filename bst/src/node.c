#include "../include/node.h"
#include <stdio.h>
#include <stdlib.h>

Node *create_node(int number) {
  Node *new_node = (Node *)malloc(sizeof(Node));
  new_node->number = number;
  new_node->left = NULL;
  new_node->right = NULL;
  return new_node;
}

void print_node(Node *node) {
  if (node == NULL) {
    printf("Node is NULL\n");
    return;
  }

  printf("Node -> number: %d", node->number);
  printf(", left: ");
  if (node->left) {
    printf("%d", node->left->number); 
  } else {
    printf("NULL");
  }
  printf(", right: ");
  if (node->right) {
    printf("%d", node->right->number);
  } else {
    printf("NULL");
  } 
  printf("\n"); 
}
