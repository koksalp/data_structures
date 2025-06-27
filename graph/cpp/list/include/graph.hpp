#ifndef GRAPH_H
#define GRAPH_H
#include "../include/linked_list.hpp"
#include "../include/node.hpp"
#include <iostream>
#include <unordered_map> 
#include <unordered_set>
#include <climits> 
// definition of the directed weighted graph
class Graph {
private:
  LinkedList *get_sub_list(int);
  std::unordered_map<int, LinkedList*> map; 
public:
  Graph();
  ~Graph();
  bool find_vertex(int vertex);
  void add_vertex(int vertex);
  void remove_vertex(int vertex);
  void add_edge(int vertex1, int vertex2, int weight);
  void remove_edge(int vertex1, int vertex2, int weight);
  void print();
  std::unordered_set<int> get_neighbors(int vertex); 
  std::vector<int> get_edge_weights(int vertex1, int vertex2); 
  int get_shortest_edge(int vertex1, int vertex2); 
};
#endif
