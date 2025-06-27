#include "../include/bst.h"
#include <stdio.h>

int main() { 
  int arr[] = {8, 4, 2, 3, 1, 7, 5, 6, 11, 9, 13, 10, 14,12};
  int size = sizeof(arr) / sizeof(int);
  int arr2[] = {20,8,18,16,-4,-2,6, 40,24,26,28};
  int size2 = sizeof(arr2) / sizeof(int);
  Node *root = create_bst(arr, size);
  Node* root2 = create_bst(arr2, size2); 
  print_bst(root, "inorder");
  print_bst(root2, "inorder");
  add_bst(&root, root2); 
  print_bst(root, "inorder");
  print_bst(root2, "inorder");
  printf("height: %d\n", get_height(root)); 
  return 0;
}
