#include <stdio.h>
#include "../include/queue.h"

int main() { 
  int arr[] = {1,2,3,4,5,6,7,8}; 
  int size = sizeof(arr) / sizeof(int); 
  Queue* q = create_queue_by_values(arr, size); 
  print_queue(q); 
  clear_queue(&q); 
  printf("find: %d\n", find(q , 5)); 
  
  return 0; 
}