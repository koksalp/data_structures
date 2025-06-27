#include "../include/node.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void add_node(Node **root_ref, int number) {
  if (root_ref == NULL) {
    return;
  }

  Node *temp = *root_ref;
  if (temp == NULL) {
    *root_ref = create_node(number);
    return;
  }

  if (temp->number > number) {
    add_node(&temp->left, number);
  } else if (temp->number < number) {
    add_node(&temp->right, number);
  }
}

Node *create_bst(int *arr, int size) {
  Node *root = NULL;
  for (int i = 0; i < size; i++) {
    add_node(&root, arr[i]);
  }

  return root;
}
void inorder(Node *root) {
  if (root == NULL) {
    return;
  }

  inorder(root->left);
  printf("%d ", root->number);
  inorder(root->right);
}

void preorder(Node *root) {
  if (root == NULL) {
    return;
  }

  printf("%d ", root->number);
  preorder(root->left);
  preorder(root->right);
}

void postorder(Node *root) {
  if (root == NULL) {
    return;
  }

  postorder(root->left);
  postorder(root->right);
  printf("%d ", root->number);
}

void print_bst(Node *root, char *method) {
  if (root == NULL) {
    printf("Tree is empty\n");
    return;
  }

  if (!strcmp(method, "inorder")) {
    inorder(root);
  } else if (!strcmp(method, "preorder")) {
    preorder(root);
  } else if (!strcmp(method, "postorder")) {
    postorder(root);
  } else {
    printf("Invalid traversal method");
  }
  printf("\n");
}

int search(Node *root, int number) {
  if (root == NULL) {
    return 0;
  }

  if (root->number > number) {
    return search(root->left, number);
  }

  if (root->number < number) {
    return search(root->right, number);
  }

  return 1;
}

Node *get_min_node(Node *root) {
  if (root == NULL || root->left == NULL) {
    return root;
  }

  return get_min_node(root->left);
}
Node *get_max_node(Node *root) {
  if (root == NULL || root->right == NULL) {
    return root;
  }

  return get_max_node(root->right);
}

Node *get_min_node_iter(Node *root) {
  if (root == NULL) {
    return root;
  }

  Node *temp = root;
  while (temp->left) {
    temp = temp->left;
  }

  return temp;
}
Node *get_max_node_iter(Node *root) {
  if (root == NULL) {
    return root;
  }

  Node *temp = root;
  while (temp->right) {
    temp = temp->right;
  }
  return temp;
}
int get_size(Node *root) {
  if (root == NULL) {
    return 0;
  }

  return get_size(root->left) + get_size(root->right) + 1;
}

int get_height(Node *root) {
  if (root == NULL) {
    return -1;
  }

  int height_left = get_height(root->left) + 1;
  int height_right = get_height(root->right) + 1;

  return height_left > height_right ? height_left : height_right;
}

void delete_node(Node **root_ref, int number) {
  if (root_ref == NULL || *root_ref == NULL) {
    return;
  }

  Node *temp = *root_ref;
  if (temp->number > number) {
    delete_node(&temp->left, number);
  } else if (temp->number < number) {
    delete_node(&temp->right, number);
  } else {
    if (temp->left == NULL) {
      *root_ref = temp->right;
    } else if (temp->right == NULL) {
      *root_ref = temp->left;
    } else {
      Node *left_max = get_max_node(temp->left);
      left_max->right = temp->right;
      *root_ref = temp->left;
    }

    free(temp);
    temp = NULL;
  }
}

void add_bst(Node **head_ref, Node *root_2) {
  if (root_2 == NULL) {
    return;
  }

  add_node(head_ref, root_2->number);
  add_bst(head_ref, root_2->left);
  add_bst(head_ref, root_2->right);
}
