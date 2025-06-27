#include "../include/graph.hpp"
#include "../include/linked_list.hpp"
#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>
#include <unordered_set> 
#include <unordered_map> 

using namespace std;
void x(char a) { cout << a << endl; }
int main() { 
  Graph* g = new Graph(); 
  g->add_vertex(1); 
  g->add_vertex(3); 
  g->add_vertex(6); 
  g->print(); 
  g->add_edge(3,6,8); 
  g->add_edge(3,6,9); 
  g->add_edge(1,3,5); 
  g->add_edge(3,1,4); 
  g->add_edge(3,6,81); 
  g->print(); 
  cout << g->get_shortest_edge(3,6) << endl; 
  return 0; 
} 
