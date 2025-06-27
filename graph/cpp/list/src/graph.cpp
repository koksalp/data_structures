#include "../include/graph.hpp"

void display_log(std::string message) {
  std::cout << "Log | " << message << std::endl;
}
Graph::Graph() { std::cout << "Graph constructor" << std::endl; }
bool Graph::find_vertex(int vertex) {
  return this->map.find(vertex) != map.end();
}

void Graph::add_vertex(int vertex) {
  if (this->find_vertex(vertex)) {
    display_log("Vertex " + std::to_string(vertex) + " already exists");
    return;
  }

  this->map.insert({vertex, new LinkedList()});
}

void Graph::print() {
  if (this->map.empty()) {
    std::cout << "Graph is empty" << std::endl;
    return;
  }

  std::cout << "GRAPH" << std::endl;
  for (const auto &pair : this->map) {
    std::cout << pair.first << ": ";
    pair.second->print();
  }
}

LinkedList *Graph::get_sub_list(int vertex) {
  auto it = this->map.find(vertex);
  return it == this->map.end() ? nullptr : it->second;
}
void Graph::add_edge(int vertex1, int vertex2, int weight) {
  if (!this->find_vertex(vertex1)) {
    display_log("edge could not be added because vertex " +
                std::to_string(vertex1) + " not found");
    return;
  }
  if (!this->find_vertex(vertex2)) {
    display_log("edge could not be added because vertex " +
                std::to_string(vertex2) + " not found");
    return;
  }

  LinkedList *sub_list = this->get_sub_list(vertex1);
  std::pair<int, int> pair = std::make_pair(vertex2, weight);
  if (sub_list->find(pair)) {
    display_log("edge could not be added because pair (" +
                std::to_string(vertex2) + ", " + std::to_string(weight) + ")" +
                " already exists.");
    return;
  }

  sub_list->add(pair);
}

void Graph::remove_edge(int vertex1, int vertex2, int weight) {
  if (!this->find_vertex(vertex1)) {
    display_log("edge could not be removed because vertex " +
                std::to_string(vertex1) + " not found");
    return;
  }
  if (!this->find_vertex(vertex2)) {
    display_log("edge could not be removed because vertex " +
                std::to_string(vertex2) + " not found");
    return;
  }

  LinkedList *sub_list = this->get_sub_list(vertex1);
  std::pair<int, int> pair = std::make_pair(vertex2, weight);
  if (!sub_list->find(pair)) {
    display_log("edge could not be removed because pair (" +
                std::to_string(vertex2) + ", " + std::to_string(weight) + ")" +
                " does not exist.");
    return;
  }
  std::unordered_map<int, int> pairs_removed = {
      std::make_pair(vertex2, weight)};
  sub_list->remove(pairs_removed);
}

Graph::~Graph() {
  for (auto &pair : this->map) {
    delete pair.second;
  }
}

void Graph::remove_vertex(int vertex) {
  if (!this->find_vertex(vertex)) {
    display_log("vertex could not be removed because vertex " +
                std::to_string(vertex) + " not found");
    return;
  }
  std::unordered_map<int, LinkedList *>::iterator it_temp;
  for (auto it = this->map.begin(); it != this->map.end(); ++it) {
    if (it->first == vertex) {
      it_temp = it;
      continue;
    }

    it->second->remove(vertex);
  }

  delete it_temp->second;
  this->map.erase(it_temp);
}

std::unordered_set<int> Graph::get_neighbors(int vertex) {
  std::unordered_set<int> neighbors;
  const auto it = this->map.find(vertex);
  if (it != this->map.end()) {

    Node *temp = it->second->get_head();
    while (temp) {
      neighbors.insert(temp->pair.first);
      temp = temp->next;
    }
  }

  return neighbors;
}

std::vector<int> Graph::get_edge_weights(int vertex1, int vertex2) {
  std::vector<int> weights;
  const auto it = this->map.find(vertex1);
  if (it != this->map.end()) {
    Node *temp = it->second->get_head();
    while (temp) {
      if (temp->pair.first == vertex2) {
        weights.push_back(temp->pair.second);
      }
      temp = temp->next;
    }
  }
  return weights;
}

int Graph::get_shortest_edge(int vertex1, int vertex2) {
  const auto it = this->map.find(vertex1);
  if (it == this->map.end()) {
    return -1;
  } 
  
  int min = INT_MAX;
  int changed=false; 
  Node *temp = it->second->get_head();
  while (temp) {
    if (temp->pair.first == vertex2 && temp->pair.second < min) {
      min = temp->pair.second;
      if (!changed) {
        changed=true; 
      }
    }
    temp = temp->next;
  }

  return changed ? min : -1;
} 
