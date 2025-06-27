#ifndef GRAPH_H
#define GRAPH_H
#include <iostream>
#include <vector>
using namespace std;

// definition of the directed weighted graph 
class Graph {
private:
  vector<vector<int>> matrix;
public:
  // constructor 
  Graph(int size=0);
  Graph(const vector<vector<int>>& arr); 
  // add 
  void add_edge(int n1, int n2, int w ); 
  void add_vertex(); 

  // remove    
  void remove_edge(int n1, int n2); 
  void remove_vertex(int n); 
  // print 
  void print() const; 
};
#endif
