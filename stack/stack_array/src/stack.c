#include "../include/stack.h"
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

Stack *create_stack() {
  Stack *stack = (Stack *)malloc(sizeof(Stack));
  stack->arr = (int *)malloc(sizeof(int) * INITIAL_LENGTH);
  stack->top = 0;
  stack->size = 0;
  stack->capacity = INITIAL_LENGTH;

  return stack;
}

void push(Stack *stack, int number) {
  if (stack->top == stack->capacity) {
    int new_capacity = stack->capacity * INCREASE_LENGTH_BY;
    int *new_array = (int *)malloc(sizeof(int) * new_capacity);
    for (int i = 0; i < stack->size; i++) {
      new_array[i] = stack->arr[i];
    }
    free(stack->arr);
    stack->arr = new_array;
    stack->capacity = new_capacity;
  }

  stack->arr[stack->top++] = number;
  stack->size++;
}

void print_stack(Stack *stack) {
  printf("Stack, size: %d capacity: %d | ", stack->size, stack->capacity);
  for (int i = 0; i < stack->size; i++) {
    printf("%d ", stack->arr[i]);
  }

  printf("\n");
}

int is_full(Stack *stack) { return stack->size == stack->capacity; }

int is_empty(Stack *stack) { return stack->size == 0; }

int peek(Stack *stack) {
  return stack->size == 0 ? INT_MIN : stack->arr[stack->top - 1];
}

int get_size(Stack *stack) { return stack->size; }

void pop(Stack *stack) {
  if (stack->top <= stack->capacity / (DECREASE_RATIO) &&
      stack->capacity / DECREASE_LENGTH_BY > INITIAL_LENGTH) {
    int decreased_capacity = stack->capacity / DECREASE_LENGTH_BY;
    int *new_array = (int *)malloc(sizeof(int) * decreased_capacity);
    for (int i = 0; i < stack->size; i++) {
      new_array[i] = stack->arr[i];
    }
    free(stack->arr);
    stack->arr = new_array;
    stack->capacity = decreased_capacity;
  }
  if (stack->top > 0) {
    stack->top--;
    stack->size--;
  }
}

void clear_stack(Stack **stack_ref) {
  if (stack_ref == NULL || *stack_ref == NULL) {
    return;
  }

  free((*stack_ref)->arr);
  free(*stack_ref);
  *stack_ref = NULL;
}

int find(Stack *stack, int number) {
  if (stack == NULL) {
    return 0;
  }

  for (int i = 0; i < stack->size; i++) {
    if (stack->arr[i] == number) {
      return 1;
    }
  }

  return 0;
}

void resize_stack(Stack *stack, int number) {
  if (number < INITIAL_LENGTH || number <= stack->size ||
      number == stack->capacity) {
    return;
  }

  int *new_array = (int *)malloc(sizeof(int) * number);

  for (int i = 0; i < stack->size; i++) {
    new_array[i] = stack->arr[i];
  }

  free(stack->arr);
  stack->arr = new_array;
  stack->capacity = number;
}

int get_min(Stack *stack) {
  int min = INT_MAX;
  if (stack == NULL) {
    return min;
  }
  for (int i = 0; i < stack->size; i++) {
    if (stack->arr[i] < min) {
      min = stack->arr[i];
    }
  }

  return min;
}

int get_max(Stack *stack) {
  int max = INT_MIN;
  if (stack == NULL) {
    return max;
  }

  for (int i = 0; i < stack->size; i++) {
    if (stack->arr[i] > max) {
      max = stack->arr[i];
    }
  }

  return max;
}

Stack *create_stack_by_values(int *arr, int size) {

  Stack *stack = create_stack();

  for (int i = 0; i < size; i++) {
    push(stack, arr[i]);
  }
  return stack;
}

int *stack_to_array(Stack *stack) {
  if (stack == NULL) {
    return NULL;
  }
  int *array = (int *)malloc(sizeof(int) * stack->size);
  for (int i = 0; i < stack->size; i++) {
    array[i] = stack->arr[i];
  }

  return array;
}

Stack *copy_stack(Stack *stack) {
  if (stack == NULL) {
    return stack;
  }
  int *array = stack_to_array(stack);
  Stack *new_stack = create_stack_by_values(array, stack->size);
  free(array);
  return new_stack;
}
