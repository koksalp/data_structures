#include "../include/graph.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
  Graph *graph = create_graph(4);
  print_graph(graph);
  add_edge(graph, 0, 3, 5);
  print_graph(graph);
  add_vertex(graph); 
  print_graph(graph);
  remove_vertex(graph, 2); 
  print_graph(graph);
  return 0;





} 