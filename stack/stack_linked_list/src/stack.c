#include "../include/stack.h"
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

Stack *create_stack() {
  Stack *stack = (Stack *)malloc(sizeof(Stack));
  stack->head = NULL;
  return stack;
}

Stack *create_stack_by_values(int *arr, int size) {
  Stack *stack = create_stack();
  for (int i = 0; i < size; i++) {
    push(stack, arr[i]);
  }
  return stack;
}
void push(Stack *stack, int number) {
  if (stack == NULL) {
    return;
  }
  Node *new_node = create_node(number);
  new_node->next = stack->head;
  stack->head = new_node;
}

void print_stack(Stack *stack) {
  if (stack == NULL || stack->head == NULL) {
    printf("Stack is empty\n");
    return;
  }

  printf("Stack: ");
  Node *temp = stack->head;
  while (temp) {
    printf("%d ", temp->number);
    temp = temp->next;
  }
  printf("\n");
}
void pop(Stack *stack) {
  if (stack == NULL || stack->head == NULL) {
    return;
  }

  Node *temp = stack->head;
  stack->head = stack->head->next;
  free(temp);
} 

int is_empty(Stack* stack) {
  return stack==NULL || stack->head==NULL;  
} 

int peek(Stack* stack) {
  if (stack==NULL || stack->head==NULL) { 
    return INT_MIN; 
  } 

  return stack->head->number; 
} 
