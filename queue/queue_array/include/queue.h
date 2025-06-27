#ifndef QUEUE_H
#define QUEUE_H
#define INITIAL_LENGTH 2
#define INCREASE_LENGTH_BY 2
#define DECREASE_LENGTH_BY 2
#define DECREASE_RATIO 4

// definition of queue
typedef struct {
  int *arr;
  int front;
  int rear;
  int size;
  int capacity;
} Queue;

Queue* create_queue( ); 
Queue* create_queue_by_values(int*, int); 
void enqueue(Queue*, int); 
void realign_queue(Queue*); 
void dequeue(Queue*); 
void print_queue(Queue*); 
int is_empty(Queue*); 
int is_full(Queue*); 
void resize_queue(Queue*, int); 
void clear_queue(Queue**); 
int peek(Queue*); 
int rear(Queue*); 
int find(Queue*, int ); 
#endif
