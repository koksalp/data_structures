#ifndef GRAPH_H
#define GRAPH_H

// definition of a directed weighted graph 
typedef struct {
  int size;
  int **matrix;
} Graph;

Graph *create_graph(int);
void print_graph(Graph *);
void add_edge(Graph *, int, int, int); 
void add_vertex(Graph*); 
void remove_edge(Graph *, int, int);
void remove_vertex(Graph*, int); 
void free_graph(Graph **);
#endif  
