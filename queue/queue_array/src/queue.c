#include "../include/queue.h"
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

Queue *create_queue() {
  Queue *q = (Queue *)malloc(sizeof(Queue));
  q->arr = (int *)malloc(sizeof(int) * INITIAL_LENGTH);
  q->front = 0;
  q->rear = 0;
  q->size = 0;
  q->capacity = INITIAL_LENGTH;

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

  if (q->rear == q->capacity) {
    if (q->front == 0) {
      int increased_capacity = q->capacity * INCREASE_LENGTH_BY;
      int *new_array = (int *)malloc(sizeof(int) * increased_capacity);
      for (int i = 0; i < q->size; i++) {
        new_array[i] = q->arr[q->front + i];
      }
      free(q->arr);
      q->arr = new_array;
      q->capacity = increased_capacity;
    } else {
      realign_queue(q);
    }
  }
  q->arr[q->rear++] = number;
  q->size++;
}

void realign_queue(Queue *q) {
  if (q == NULL || q->arr == NULL || q->front == 0) {
    return;
  }
  for (int i = 0; i < q->size; i++) {
    q->arr[i] = q->arr[q->front + i];
  }
  q->rear -= q->front;
  q->front = 0;
}

void dequeue(Queue *q) {
  if (q == NULL || q->arr == NULL || q->front == q->rear) {
    return;
  }

  q->front++;
  q->size--;
  if (q->size < q->capacity / DECREASE_RATIO &&
      q->capacity / DECREASE_LENGTH_BY >= INITIAL_LENGTH) {
    resize_queue(q, q->capacity / DECREASE_LENGTH_BY);
  }
}

void print_queue(Queue *q) {
  if (q == NULL) {
    printf("Queue is NULL\n");
    return;
  }
  printf("Queue, size: %d capacity: %d front: %d rear: %d | ", q->size,
         q->capacity, q->front, q->rear);

  for (int i = q->front; i < q->rear; i++) {
    printf("%d ", q->arr[i]);
  }
  printf("\n");
}
int is_empty(Queue *q) { return q == NULL || q->front == q->rear; }

int is_full(Queue *q) { return !q && q->size == q->capacity; }

void resize_queue(Queue *q, int capacity) {
  if (q == NULL || capacity <= q->size || capacity < INITIAL_LENGTH) {
    return;
  }

  int *new_array = (int *)malloc(sizeof(int) * capacity);
  for (int i = 0; i < q->size; i++) {
    new_array[i] = q->arr[q->front + i];
  }

  free(q->arr);
  q->arr = new_array;
  q->capacity = capacity;
  q->front = 0;
  q->rear = q->size;
}

void clear_queue(Queue **q_ref) {
  if (q_ref == NULL || *q_ref == NULL) {
    return;
  }

  free((*q_ref)->arr);
  free(*q_ref);
  *q_ref = NULL;
}

int peek(Queue *q) {
  if (q == NULL || q->size == 0) {
    return INT_MIN;
  }

  return q->arr[q->front];
}

int rear(Queue *q) {
  if (q == NULL || q->size == 0) {
    return INT_MIN;
  }

  return q->arr[q->rear - 1];
}

int find(Queue *q, int number) {
  if (q == NULL) {
    return 0;
  }

  for (int i = q->front; i < q->rear; i++) {
    if (q->arr[i] == number) {
      return 1;
    }
  }

  return 0;
}
