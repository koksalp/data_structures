#include "../include/graph.hpp"

void print_message(string message) { cout << "Log | " << message << endl; }
Graph::Graph(int size) {
  if (size <= 0) {
    return;
  }

  this->matrix.resize(size, vector<int>(size));
}

void Graph::print() const {
  if (this->matrix.empty()) {
    cout << "Graph is empty" << endl;
    return;
  }

  cout << "GRAPH" << endl;
  for (int i = 0; i < this->matrix.size(); i++) {
    cout << i << ": ";
    for (int j = 0; j < this->matrix.size(); j++) {
      cout << this->matrix[i][j] << " ";
    }
    cout << endl;
  }
}

void Graph::add_edge(int n1, int n2, int w) {
  if (n1 < 0 || n2 < 0 || n1 >= this->matrix.size() ||
      n2 >= this->matrix.size() || w <= 0) {
    print_message("invalid args");
    return;
  }

  this->matrix[n1][n2] = w;
}

void Graph::remove_edge(int n1, int n2) {
  if (n1 < 0 || n2 < 0 || n1 >= this->matrix.size() ||
      n2 >= this->matrix.size()) {
    print_message("invalid args");
    return;
  }

  this->matrix[n1][n2] = 0;
}

void Graph::add_vertex() {
  int new_size = this->matrix.size() + 1;
  this->matrix.resize(new_size);
  for (auto &row : this->matrix) {
    row.resize(new_size);
  }
}

Graph::Graph(const vector<vector<int>> &arr) {
  int size = arr.size();
  for (const auto &row : arr) {
    if (row.size() != size) {
      print_message("matrix should be square");
      return;
    }
  }

  this->matrix = arr;
}

void Graph::remove_vertex(int n) {
  if (n < 0 || n >= this->matrix.size() || this->matrix.empty()) {
    print_message("vertex could not be removed");
    return;
  }
  int new_size = this->matrix.size() - 1;
  vector<vector<int>> new_arr(new_size, vector<int>(new_size));
  int skip_row = 0;
  for (int i = 0; i < new_size; i++) {
    int skip_column = 0;
    if (!skip_row && i == n) {
      skip_row = 1;
    }
    for (int j = 0; j < new_size; j++) {
      if (!skip_column && j == n) {
        skip_column = 1;
      }
      new_arr[i][j] = this->matrix[i + skip_row][j + skip_column];
    }
  }
  this->matrix = new_arr;
}
