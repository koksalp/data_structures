#ifndef QUEUE_H
#define QUEUE_H
#include "node.h"

typedef struct {
  Node *front;
  Node *rear;
  int size;
} Queue;

Queue *create_queue();
Queue *create_queue_by_values(int *, int);
void enqueue(Queue *, int);
void dequeue(Queue *);
void print_queue(Queue *);
void clear_queue(Queue **);
int peek(Queue *);
int rear(Queue *);
int get_size(Queue *);
int is_empty(Queue *);
#endif
