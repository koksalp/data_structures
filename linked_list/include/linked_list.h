#ifndef LINKED_LIST_H
#define LINKED_LIST_H
#include "node.h"

// CREATE
// create a linked list using the array passed as arg
Node *create(int *, int);

// ADD
// add node to a linked list
void add_node(Node **, int);

// REMOVE
// remove all nodes from a linked list that matches the number
void remove_node(Node **, int);
// remove node from a linked list by index
void remove_node_by_index(Node **, int);
// remove all the duplicates
void remove_duplicates(Node *);

// CLEAR
// free memory linked list occupies
void clear(Node **);

// SORT
// bubble sort
void sort(Node *);

// MIN MAX
Node *get_min_node(Node *);
Node *get_max_node(Node *);
int get_max_frequency(Node*); 
int get_min_frequency(Node*); 
// PRINT
void print(Node *);

// SEARCH
// 1 if found else 0
int search(Node *, int);
// index of the first node that has the given number
int index_of(Node *, int);
// index of the last node that has the given number
int last_index_of(Node *, int);

// CUSTOM OPERATIONS
// reverse a linked list
void reverse(Node **);
// copy second linked list and add it at the end of the first linked list
void merge(Node **, Node *);
// frequency of a number in a linked list
int count(Node *, int);
// copy a linked list
Node *copy(Node *);
// get the middle node of a linked list
Node *get_middle_node(Node *);
// get the node located at the specific index
Node *get_node_by_index(Node *, int);
// add duplicate nodes to linked list
void add_duplicate(Node *, int);

int is_palindrome(Node *);
int is_same(Node *, Node *);
Node *slice(Node *, int);
int get_length(Node *);

#endif
