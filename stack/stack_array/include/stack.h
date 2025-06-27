#ifndef STACK_H
#define STACK_H
#define INITIAL_LENGTH 2
#define INCREASE_LENGTH_BY 2
#define DECREASE_LENGTH_BY 2
#define DECREASE_RATIO 4

// definition of a stack
typedef struct {
  int *arr;
  int top;
  int capacity;
  int size;
} Stack;

// create an empty stack
Stack *create_stack();

// push int to stack
void push(Stack *, int);

// pop int from the stack
void pop(Stack *);

// print stack
void print_stack(Stack *);

// check if a stack is full
int is_full(Stack *);

// check if a stack is empty
int is_empty(Stack *);

// retrieve the element on top of a stack
int peek(Stack *);

// get size of a stack
int get_size(Stack *);

// search a number in the stack
int find(Stack *, int);

// resize the capacity of a stack
void resize_stack(Stack *, int);

// free stack
void clear_stack(Stack **);

// get min
int get_min(Stack *);

// get max
int get_max(Stack *);

// create a stack with an array 
Stack* create_stack_by_values(int*, int); 

int* stack_to_array(Stack*); 
Stack* copy_stack(Stack*); 
#endif
