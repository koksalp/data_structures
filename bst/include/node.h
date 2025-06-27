#ifndef NODE_H
#define NODE_H

/* Definition of Node */
typedef struct Node {
  int number;
  struct Node *left;
  struct Node *right;
} Node;

// create
Node *create_node(int);

// print
void print_node(Node *);

#endif
