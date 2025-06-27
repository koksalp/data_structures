#ifndef LINKED_LIST
#define LINKED_LIST

#include "node.hpp"
#include <iostream>
#include <unordered_map>
#include <vector>

class LinkedList {
private:
  Node *head;

public:
  LinkedList();
  LinkedList(std::vector<std::pair<int, int>> &v);
  ~LinkedList();
  void clear();
  void add(const std::pair<int, int> &pair);
  void add(const std::vector<std::pair<int, int>> &v);
  void remove(const std::unordered_map<int, int> &map);
  void remove(int value, bool both = false);
  void print();
  bool find(const std::pair<int, int> &pair);
  bool is_empty() const;
  Node *get_head() const; 
};

#endif
