#include "singly_linked_list.h"
#include <stddef.h>
#include <stdlib.h>

static Node *prev_node_at(Node *head, size_t n) {
  Node *current = head;
  Node *prev = NULL;

  if (current) {
    size_t i = 0;
    while (i != n && current) {
      prev = current;
      current = current->next;
      ++i;
    }
    if (i != n)
      return NULL;
    else
      return prev;
  }
  return prev;
}

Node *insert_at(Node **head, size_t n, Node *node) {
  if (!head || !node) {
    return NULL;
  }

  if (!n) {
    node->next = *head;
    *head = node;
    return node;
  }

  Node *prev_node = prev_node_at(*head, n);
  if (!prev_node) {
    // index out of range; you could decide to append or ignore
    return NULL;
  }

  Node *next_node = prev_node->next;
  prev_node->next = node;
  node->next = next_node;
  return node;
}

size_t list_len(Node *head) {
  Node *current = head;
  if (current) {
    size_t len = 1;
    while ((current = current->next)) {
      ++len;
    }
    return len;
  }
  return 0;
}

Node *node_at(Node *head, size_t n) {
  Node *current = head;

  for (size_t i = 0; i < n;) {
    if (current) {
      current = current->next;
      ++i;
    } else {
      return NULL;
    }
  }
  return current;
}

void *delete_at(Node **head, size_t n) {
  if (!head || !*head) {
    return NULL;
  }

  Node *current = *head;

  // delete head
  if (!n) {
    *head = current->next;
    void *data = current->data;
    free(current);
    return data;
  } else {
    Node *prev = prev_node_at(*head, n);
    if (!prev || !prev->next) {
      // index out of range
      return NULL;
    }

    Node *node_to_be_deleted = prev->next;
    prev->next = node_to_be_deleted->next;

    void *data = node_to_be_deleted->data;
    free(node_to_be_deleted);
    return data;
  }
}

Node *tail(Node *head) {
  Node *current = head;
  if (current) {
    while (current->next) {
      current = current->next;
    }
    return current;
  }
  return current;
}
