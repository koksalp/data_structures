#include "../include/linked_list.hpp"

LinkedList::LinkedList() { this->head = nullptr; }

LinkedList::LinkedList(std::vector<std::pair<int, int>> &v) {
  this->head = nullptr;
  this->add(v);
}

void LinkedList::add(const std::pair<int, int> &pair) {
  Node *new_node = new Node(pair);
  if (!this->head) {
    this->head = new_node;
    return;
  }
  Node *temp = this->head;
  while (temp->next) {
    temp = temp->next;
  }

  temp->next = new_node;
}
void LinkedList::add(const std::vector<std::pair<int, int>> &v) {
  if (v.empty()) {
    return;
  }

  Node *temp = this->head;
  if (temp) {
    while (temp->next) {
      temp = temp->next;
    }
  }
  for (const auto &pair : v) {
    Node *new_node = new Node(pair);
    if (temp) {
      temp->next = new_node;
      temp = temp->next;
    } else {
      this->head = new_node;
      temp = this->head;
    }
  }
}

void LinkedList::print() {
  if (!this->head) {
    std::cout << "Linked list is empty" << std::endl;
    return;
  }

  Node *temp = this->head;
  while (temp) {
    std::cout << temp->get_pair_string() << " ";
    temp = temp->next;
  }
  std::cout << std::endl;
}

LinkedList::~LinkedList() { this->clear(); }

void LinkedList::clear() {
  Node *temp = this->head;
  Node *prev = nullptr;

  while (temp) {
    prev = temp;
    temp = temp->next;
    delete prev;
  }

  this->head = nullptr;
}
void LinkedList::remove(const std::unordered_map<int, int> &map) {
  Node *temp = this->head;
  Node *prev = nullptr;

  while (temp) {
    if (map.find(temp->pair.first) != map.end() &&
        map.at(temp->pair.first) == temp->pair.second) {
      if (prev) {
        prev->next = temp->next;
        delete temp;
        temp = prev->next;
      } else {
        this->head = this->head->next;
        delete temp;
        temp = this->head;
      }
    } else {
      prev = temp;
      temp = temp->next;
    }
  }
}

bool LinkedList::find(const std::pair<int, int> &pair) {
  Node *temp = this->head;
  while (temp) {
    if (temp->pair.first == pair.first && temp->pair.second == pair.second) {
      return true;
    }
    temp = temp->next;
  }

  return false;
}

void LinkedList::remove(int value, bool both) {
  Node *temp = this->head;
  Node *prev = nullptr;

  while (temp) {
    if (temp->pair.first == value || (both && temp->pair.second == value)) {
      if (prev) {
        prev->next = temp->next;
        delete temp;
        temp = prev->next;
      } else {
        this->head = this->head->next;
        delete temp;
        temp = this->head;
      }
    } else {
      prev = temp;
      temp = temp->next;
    }
  }
}

bool LinkedList::is_empty() const { return this->head == nullptr; }
Node *LinkedList::get_head() const { return this->head; }
