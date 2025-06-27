#include "../include/graph.h"
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
Graph *create_graph(int size) {
  Graph *graph = (Graph *)malloc(sizeof(Graph));
  if (graph == NULL) {
    return NULL;
  }
  graph->size = size;
  graph->matrix = (int **)malloc(sizeof(int *) * size);
  if (graph->matrix == NULL) {
    // free allocated memory in case malloc fails
    free(graph);
    return NULL;
  }
  for (int i = 0; i < size; i++) {
    graph->matrix[i] = (int *)calloc(size, sizeof(int));
    // free allocated rows, 2d matrix and graph just in case calloc fails
    if (graph->matrix[i] == NULL) {
      for (int j = 0; j < i; j++) {
        free(graph->matrix[j]);
      }
      free(graph->matrix);
      free(graph);
      return NULL;
    }
  }

  return graph;
}
void print_graph(Graph *graph) {
  if (graph == NULL || graph->matrix == NULL) {
    printf("Graph is null\n");
    return;
  }
  printf("GRAPH\n");
  for (int i = 0; i < graph->size; i++) {
    for (int j = 0; j < graph->size; j++) {
      printf("%d ", graph->matrix[i][j]);
    }
    printf("\n");
  }
}

void add_edge(Graph *graph, int n1, int n2, int w) {
  if (n1 < 0 || n2 < 0 || n1 >= graph->size || n2 >= graph->size ||
      graph->matrix[n1][n2] || w <= 0) {
    return;
  }

  graph->matrix[n1][n2] = w;
}

void remove_edge(Graph *graph, int n1, int n2) {
  if (n1 < 0 || n2 < 0 || n1 >= graph->size || n2 >= graph->size ||
      !graph->matrix[n1][n2]) {
    return;
  }

  graph->matrix[n1][n2] = 0;
}

void free_graph(Graph **graph_ref) {
  // check if pointers are null just in case
  if (graph_ref == NULL || *graph_ref == NULL || (*graph_ref)->matrix == NULL) {
    return;
  }

  Graph *graph = *graph_ref;
  for (int i = 0; i < graph->size; i++) {
    // check if the row is allocated
    // although free(NULL) is also ok - no op
    if (graph->matrix[i]) {
      free(graph->matrix[i]);
    }
  }
  free(graph->matrix);
  free(graph);
  *graph_ref = NULL;
}

int **create_2d_arr(int size) {
  if (size <= 0) {
    return NULL;
  }
  int **new_arr = (int **)malloc(sizeof(int *) * size);
  if (!new_arr) {
    perror("failed to allocate memory");
    return NULL;
  }
  for (int i = 0; i < size; i++) {
    new_arr[i] = (int *)calloc(size, sizeof(int));
    if (!new_arr[i]) {
      perror("failed to allocate memory");
      for (int j = 0; j < i; j++) {
        free(new_arr[j]);
      }
      free(new_arr);
      return NULL;
    }
  }

  return new_arr;
}

void free_2d_arr(int ***arr_ref, int rows) {
  if (!arr_ref || !(*arr_ref) || !(**arr_ref)) {
    return;
  }

  int **arr = *arr_ref;

  for (int i = 0; i < rows; i++) {
    free(arr[i]);
  }
  free(arr);
  *arr_ref = NULL;
}
void add_vertex(Graph *graph) {
  if (graph == NULL) {
    return;
  }
  int new_size = graph->size + 1;
  int **new_arr = create_2d_arr(new_size);
  if (!new_arr) {
    return;
  }
  for (int i = 0; i < graph->size; i++) {
    for (int j = 0; j < graph->size; j++) {
      new_arr[i][j] = graph->matrix[i][j];
    }
  }

  free_2d_arr(&graph->matrix, graph->size);
  graph->matrix = new_arr;
  graph->size = new_size;
}

void remove_vertex(Graph *graph, int index) {
  if (!graph || !graph->matrix || index < 0 || index >= graph->size) {
    return;
  }

  int new_size = graph->size - 1;
  int **new_arr = create_2d_arr(new_size);
  if (!new_arr) {
    return;
  }
  int skip_row = 0;
  for (int i = 0; i < new_size; i++) {
    int skip_column = 0;
    if (!skip_row && i == index) {
      skip_row = 1;
    }
    for (int j = 0; j < new_size; j++) {
      if (!skip_column && j == index) {
        skip_column = 1;
      }
      new_arr[i][j] = graph->matrix[i + skip_row][j + skip_column];
    }
  }

  free_2d_arr(&graph->matrix, graph->size);
  graph->matrix = new_arr;
  graph->size = new_size;
}
