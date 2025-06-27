#include "../include/stack.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
  int x[] = {1, 2, 3, 4, 5, 6, 7, 8};
  int y = sizeof(x) / sizeof(int);
  Stack *stack = create_stack_by_values(x, y);
  return 0;
}
