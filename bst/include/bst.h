#ifndef BST_H
#define BST_H
#include "node.h"

// CREATE
// create a bst using the array passed as arg
Node *create_bst(int *, int);

// ADD
void add_node(Node **, int);
void add_bst(Node **, Node *);
// PRINT
void print_bst(Node *, char *);
void inorder(Node *);
void preorder(Node *);
void postorder(Node *);

// SEARCH
int search(Node *, int);

// MIN MAX
Node *get_min_node(Node *);
Node *get_max_node(Node *);
Node *get_min_node_iter(Node *);
Node *get_max_node_iter(Node *);

// DELETE
void delete_node(Node **, int);

// COUNT
int get_size(Node *);

int get_height(Node *);
#endif
