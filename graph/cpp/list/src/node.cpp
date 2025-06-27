#include "../include/node.hpp"

Node::Node(const std::pair<int, int> &pair) {
  this->pair = std::make_pair(pair.first, pair.second);
  this->next = nullptr;
}

void Node::print() {
  std::string node_info = "(" + std::to_string(this->pair.first) + ", " +
                          std::to_string(this->pair.second) + ")";
  std::string next_info =
      this->next ? "(" + std::to_string(this->next->pair.first) + ", " +
                       std::to_string(this->next->pair.second) + ")"
                 : "null";
  std::cout << "Node: " << node_info << " | next: " << next_info << std::endl;
}

std::string Node::get_pair_string() {
  std::string node_string = "(" + std::to_string(this->pair.first) + ", " +
                            std::to_string(this->pair.second) + ")";
  return node_string;
}
