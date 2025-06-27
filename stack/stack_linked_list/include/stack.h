#ifndef STACK_H
#define STACK_H
#include "node.h"

// definition of a stack
typedef struct {
  Node *head;
} Stack;

Stack *create_stack();
Stack *create_stack_by_values(int *, int);
void push(Stack *, int);
void print_stack(Stack *);
void pop(Stack *);
int is_empty(Stack*); 
int peek(Stack*); 
#endif
