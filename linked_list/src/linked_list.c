#include "../include/linked_list.h"
#include "../include/node.h"
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

Node *create(int *arr, int size) {
  Node *head = NULL;
  for (int i = 0; i < size; i++) {
    add_node(&head, arr[i]);
  }

  return head;
}
void add_node(Node **head_ref, int number) {
  if (head_ref == NULL) {
    return;
  }

  Node *new_node = create_node(number);
  if (*head_ref == NULL) {
    *head_ref = new_node;
    return;
  }

  Node *temp = *head_ref;
  while (temp->next) {
    temp = temp->next;
  }

  temp->next = new_node;
}

void print(Node *head) {
  if (head == NULL) {
    printf("Linked list is empty\n");
    return;
  }

  printf("Linked list: ");
  Node *temp = head;
  while (temp) {
    printf("%d ", temp->number);
    temp = temp->next;
  }

  printf("\n");
}

void remove_node(Node **head_ref, int number) {
  if (head_ref == NULL || *head_ref == NULL) {
    return;
  }

  Node *prev = NULL;
  Node *temp = *head_ref;
  while (temp) {
    if (temp->number == number) {
      if (prev) {
        temp = temp->next;
        free(prev->next);
        prev->next = temp;
      } else {
        *head_ref = temp->next;
        free(temp);
        temp = *head_ref;
      }
    } else {
      prev = temp;
      temp = temp->next;
    }
  }
}

void clear(Node **head_ref) {
  if (head_ref == NULL || *head_ref == NULL) {
    return;
  }

  Node *current = *head_ref;
  Node *next = current->next;

  while (current) {
    free(current);
    current = next;
    if (next) {
      next = next->next;
    }
  }

  *head_ref = NULL;
}

void remove_node_by_index(Node **head_ref, int index) {
  if (head_ref == NULL || *head_ref == NULL) {
    return;
  }

  Node *prev = NULL;
  Node *temp = *head_ref;
  int i = 0;
  while (temp->next && i < index) {
    prev = temp;
    temp = temp->next;
    i++;
  }

  if (i != index) {
    return;
  }

  if (prev) {
    prev->next = temp->next;
  } else {
    *head_ref = temp->next;
  }
  free(temp);
}

void sort(Node *head) {
  if (head == NULL || head->next == NULL) {
    return;
  }

  Node *temp = NULL;
  int sorted;
  while (1) {
    temp = head;
    sorted = 1;
    while (temp->next) {
      if (temp->number > temp->next->number) {
        int val = temp->number;
        temp->number = temp->next->number;
        temp->next->number = val;
        if (sorted) {
          sorted = 0;
        }
      }
      temp = temp->next;
    }

    if (sorted) {
      break;
    }
  }
}
Node *get_min_node(Node *head) {
  if (head == NULL || head->next == NULL) {
    return head;
  }
  Node *temp = head;
  Node *min_node = NULL;
  int min = INT_MAX;
  while (temp) {
    if (temp->number < min) {
      min = temp->number;
      min_node = temp;
    }
    temp = temp->next;
  }
  return min_node;
}
Node *get_max_node(Node *head) {
  if (head == NULL || head->next == NULL) {
    return head;
  }
  Node *temp = head;
  Node *max_node = NULL;
  int max = INT_MIN;
  while (temp) {
    if (temp->number > max) {
      max = temp->number;
      max_node = temp;
    }
    temp = temp->next;
  }
  return max_node;
}

void reverse(Node **head_ref) {
  if (head_ref == NULL || *head_ref == NULL) {
    return;
  }

  Node *prev = NULL;
  Node *temp = *head_ref;
  Node *next = temp->next;

  while (temp) {
    temp->next = prev;
    prev = temp;
    temp = next;
    if (next) {
      next = next->next;
    }
  }

  *head_ref = prev;
}

Node *copy(Node *head) {
  Node *head_copy = NULL;
  Node *temp_copy = NULL;
  Node *temp = head;
  while (temp) {
    Node *new_node = create_node(temp->number);
    if (head_copy == NULL) {
      head_copy = new_node;
      temp_copy = head_copy;
    } else {
      temp_copy->next = new_node;
      temp_copy = temp_copy->next;
    }
    temp = temp->next;
  }

  return head_copy;
}

void merge(Node **first_ref, Node *second) {
  if (first_ref == NULL) {
    return;
  }

  Node *second_copy = copy(second);
  if (*first_ref == NULL) {
    *first_ref = second_copy;
    return;
  }

  Node *temp = *first_ref;
  while (temp->next) {
    temp = temp->next;
  }

  temp->next = second_copy;
}

Node *get_middle_node(Node *head) {
  if (head == NULL || head->next == NULL) {
    return head;
  }

  Node *slow = head, *fast = head;
  while (fast->next && fast->next->next) {
    slow = slow->next;
    fast = fast->next->next;
  }

  return slow;
}

Node *get_node_by_index(Node *head, int index) {
  if (head == NULL || index < 0) {
    return NULL;
  }

  Node *temp = head;
  int i = 0;
  while (temp && i < index) {
    temp = temp->next;
    i++;
  }

  return temp;
}

int search(Node *head, int number) {
  Node *temp = head;
  while (temp) {
    if (temp->number == number) {
      return 1;
    }
    temp = temp->next;
  }

  return 0;
}

int index_of(Node *head, int number) {
  int i = 0;
  Node *temp = head;

  while (temp) {
    if (temp->number == number) {
      return i;
    }
    temp = temp->next;
    i++;
  }

  return -1;
}
int last_index_of(Node *head, int number) {
  int index = -1;
  int i = 0;
  Node *temp = head;
  while (temp) {
    if (temp->number == number) {
      index = i;
    }
    temp = temp->next;
    i++;
  }

  return index;
}

int count(Node *head, int number) {
  int freq = 0;
  Node *temp = head;
  while (temp) {
    if (temp->number == number) {
      freq++;
    }
    temp = temp->next;
  }

  return freq;
}

void remove_duplicates(Node *head) {
  if (head == NULL) {
    return;
  }

  /*
    linked list is a very inefficient data structure to use as a set
    because the time complexity of searching a number is O(n)
    but it does not matter since we are practicing now
  */
  // create a linked list and use it as a set to detect duplicates.
  Node *set = NULL;

  Node *prev = NULL;
  Node *temp = head;
  while (temp) {
    if (search(set, temp->number)) {
      prev->next = temp->next;
      free(temp);
      temp = prev->next;
    } else {
      add_node(&set, temp->number);
      prev = temp;
      temp = temp->next;
    }
  }

  clear(&set);
}

void add_duplicate(Node *head, int freq) {
  if (freq < 1) {
    return;
  }
  Node *temp = head;
  while (temp) {
    int number = temp->number;
    for (int i = 0; i < freq; i++) {
      Node *new_node = create_node(number);
      new_node->next = temp->next;
      temp->next = new_node;
      temp = new_node;
    }
    temp = temp->next;
  }
}

int is_same(Node *first, Node *second) {
  Node *f = first, *s = second;
  while (f && s) {
    if (f->number != s->number) {
      return 0;
    }

    f = f->next;
    s = s->next;
  }

  return !f && !s;
}
Node *slice(Node *head, int number) {
  Node *head_copy = NULL;
  Node *temp_copy = NULL;
  Node *temp = head;
  int i = 0;
  while (temp && i < number) {
    Node *new_node = create_node(temp->number);
    if (head_copy == NULL) {
      head_copy = new_node;
      temp_copy = head_copy;
    } else {
      temp_copy->next = new_node;
      temp_copy = temp_copy->next;
    }
    temp = temp->next;
    i++;
  }
  return head_copy;
}

int get_length(Node *head) {
  int i = 0;
  for (Node *temp = head; temp; temp = temp->next) {
    i++;
  }
  return i;
}
// a better algorithm can be written in terms of
// both space and time complexity
// but the idea here is to use helper functions
// and no other logic
int is_palindrome(Node *head) {
  Node *second = copy(get_middle_node(head));
  reverse(&second);
  Node *first_copy = slice(head, get_length(second));
  return is_same(first_copy, second);
}

int get_max_frequency(Node* head    ) { 
  int max = INT_MIN; 
  int freq=0; 
  int num; 
  Node* temp = head; 
  while (temp) {
    num=temp->number; 
    if (num>max) { 
      max=num;
      freq=1;  
    } else if (num==max) {
      freq++; 
    } 
    temp=temp->next; 
  } 
  return freq; 
} 

int get_min_frequency(Node* head    ) { 
  int min = INT_MAX; 
  int freq=0; 
  int num; 
  Node* temp = head; 
  while (temp) {
    num=temp->number; 
    if (num<min) { 
      min=num;
      freq=1;  
    } else if (num==min) {
      freq++; 
    } 
    temp=temp->next; 
  } 
  return freq; 
} 
