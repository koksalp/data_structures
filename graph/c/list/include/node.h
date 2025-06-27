#ifndef NODE_H
#define NODE_H

typedef struct Node {
  int arr[2]; 
  struct Node* next; 
} Node; 

Node* create_node(int arr[2]); 
void print_node(Node*); 
void free_node(Node**); 
#endif  
