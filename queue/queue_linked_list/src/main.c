#include "../include/queue.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
  int x[] = {1, 2, 3, 4};
  int y = sizeof(x) / sizeof(int);
  Queue* q = create_queue_by_values(x, y);
  print_queue(q ); 
  enqueue(q , 5); 
  print_queue(q );
  enqueue(q , 6); 
  print_queue(q );
  enqueue(q , 7); 
  print_queue(q );
  enqueue(q , 8); 
  print_queue(q );
  dequeue(q ); 
  print_queue(q );
  dequeue(q ); 
  print_queue(q );
  dequeue(q ); 
  print_queue(q );
  dequeue(q ); 
  print_queue(q );
  dequeue(q ); 
  print_queue(q );
  dequeue(q ); 
  print_queue(q );
  dequeue(q ); 
  print_queue(q );
  dequeue(q ); 
  print_queue(q );
  dequeue(q ); 
  print_queue(q );
  dequeue(q ); 
  print_queue(q );
  clear_queue(&q ); 
  print_queue(q );
  q=create_queue(); 
  print_queue(q );
  enqueue(q , 8 ); 
  print_queue(q );
  enqueue(q , 18 ); 
  print_queue(q );
  dequeue(q ); 
  print_queue(q );
  dequeue(q ); 
  print_queue(q );
  dequeue(q ); 
  print_queue(q );
  printf("%d\n", is_empty(q )); 
  enqueue(q , 8 ); 
  print_queue(q );
  printf("%d\n", is_empty(q )); 

  return 0;
}
