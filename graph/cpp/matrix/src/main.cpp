#include "../include/graph.hpp"
#include <iostream>
#include <vector>
using namespace std;
void print(vector<int> &arr) {
  for (int i : arr) {
    cout << i << " ";
  }
  cout << endl;
}
void print_2d(vector<vector<int>> &arr) {
  int i=0;
  for (auto &row : arr) {
    cout << i++ << ": "; 
    for (int num : row) {
      cout << num << " ";
    }
    cout << endl;
  }
}
int main() {
  vector<vector<int>> arr = {
    {0,1,2,3}, 
    {1,2,3,4}, 
    {2,3,4,5}, 
    {3,4,5,6}, 
  };
  Graph *graph = new Graph(arr);
  graph->print();
  graph->remove_vertex(3); 
  graph->print();
  return 0;
}
