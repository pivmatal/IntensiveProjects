#include "list.h"
#include "door_struct.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


struct node *init(struct door *door) {
  struct node *root = (struct node *)malloc(sizeof(struct node));
  root->door_elem.id = door->id;
  root->door_elem.status = door->status;
  root->next = NULL;
  return root;
}

struct node *add_door(struct node *elem, struct door *door) {
  struct node *new_door = (struct node *)malloc(sizeof(struct node));
  new_door->next = elem->next;
  elem->next = new_door;
  new_door->door_elem.status = door->status;
  new_door->door_elem.id = rand() % 10000;
  return new_door;
}

struct node *find_door(int door_id, struct node *root) {
  struct node *ptr = root;
  while (ptr != NULL && ptr->door_elem.id != door_id) {
    ptr = ptr->next;
  }
  return ptr;
}

struct node *remove_door(struct node *elem, struct node *root) {
  struct node *ptr = root;
  if (elem == root) {
    root = root->next;
    free(elem);
  } else {
    while (ptr != NULL && ptr->next != elem) {
      ptr = ptr->next;
    }
    if (ptr->next == elem) {
      ptr->next = elem->next;
      free(elem);
    }
    if (ptr == NULL) {
      root = NULL;
    }
  }
  return root;
}

void destroy(struct node *root) {
  struct node *prev = root;
  while (root != NULL) {
    root = root->next;
    free(prev);
    prev = root;
  }
}
