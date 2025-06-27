#include "../include/queue.h"
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

Queue *create_queue() {
  Queue *q = (Queue *)malloc(sizeof(Queue));
  q->front = NULL;
  q->rear = NULL;
  q->size = 0;

  return q;
}
Queue *create_queue_by_values(int *arr, int size) {
  Queue *q = create_queue();
  for (int i = 0; i < size; i++) {
    enqueue(q, arr[i]);
  }
  return q;
}
void enqueue(Queue *q, int number) {
  if (q == NULL) {
    return;
  }

  Node *new_node = create_node(number);
  if (q->rear == NULL) {
    q->front = new_node;
    q->rear = new_node;
    q->size++;
    return;
  }

  q->rear->next = new_node;
  q->rear = new_node;
  q->size++;
}

void print_queue(Queue *q) {
  if (q == NULL) {
    printf("Queue is NULL\n");
    return;
  }
  printf("Queue, size: %d | ", q->size);
  Node *temp = q->front;
  while (temp) {
    printf("%d ", temp->number);
    temp = temp->next;
  }
  printf("\n");
}

void dequeue(Queue *q) {
  if (q == NULL || q->front == NULL) {
    return;
  }

  Node *temp = q->front;
  q->front = q->front->next;
  free(temp);
  q->size--;
}

void clear_queue(Queue **q_ref) {
  if (q_ref == NULL || *q_ref == NULL) {
    return;
  }

  Node *temp = (*q_ref)->front;
  Node *prev = NULL;
  while (temp) {
    prev = temp;
    temp = temp->next;
    free(temp);
  }
  free(*q_ref);
  *q_ref = NULL;
}

int peek(Queue *q) {
  if (q == NULL || q->front == NULL) {
    return INT_MIN;
  }

  return q->front->number;
}
int rear(Queue *q) {
  if (q == NULL || q->rear == NULL) {
    return INT_MIN;
  }

  return q->rear->number;
}
int get_size(Queue *q) {
  if (q == NULL) {
    return -1;
  }

  return q->size;
}
int is_empty(Queue *q) {
  if (q == NULL) {
    return -1;
  }

  return !q->size;
}
