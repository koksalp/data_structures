#ifndef NODE_H
#define NODE_H
#include <iostream>
#include <utility>

class Node {
public:
  std::pair<int, int> pair;
  struct Node *next;

  Node(const std::pair<int, int> &);
  void print();
  std::string  get_pair_string(); 
};
#endif
