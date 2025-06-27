#include "../include/stack.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
  int x[] = {1, 2, 3, 4};
  int y = sizeof(x) / sizeof(int);
  Stack *stack = create_stack_by_values(x, y);
  print_stack(stack); 
  return 0;
}
