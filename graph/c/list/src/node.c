#include "../include/node.h"
#include <stdio.h>
#include <stdlib.h>

Node *create_node(int arr[2]) {
  Node *node = (Node *)malloc(sizeof(Node));
  node->arr[0] = arr[0];
  node->arr[1] = arr[1];
  node->next = NULL;

  return node;
}
void print_node(Node *node) {
  if (node == NULL) {
    printf("Node is null\n");
    return;
  }

  printf("Node: {%d, %d} | next: %s\n", node->arr[0], node->arr[1],
         node->next ? "NOT NULL" : "NULL");
}

void free_node(Node **node_ref) {
  // no need to check if *node_ref is NULL
  // since free(NULL) is also ok
  if (!node_ref) {
    return;
  }

  free(*node_ref);
  *node_ref = NULL;
}
