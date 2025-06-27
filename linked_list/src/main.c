#include "../include/linked_list.h"
#include <stdio.h>

int main() {
  int arr[] = {}; 
  int size = sizeof(arr) / sizeof(int);
  Node *ll = create(arr, size);
  print(ll); 
  printf("min: %d max: %d\n", get_min_frequency(ll), get_max_frequency(ll)); 
  return 0;
}
