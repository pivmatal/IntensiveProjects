#include "door_struct.h"
#include "list.h"
#include <stdio.h>
#include <stdlib.h>

void add_door_test(struct node *elem, struct door *door, struct node *root);
void remove_door_test(struct node *elem, struct node *root);

int main() {
  struct door doors[0];
  struct node *root;
  root = init(doors);

  add_door_test(root, doors, root);
  struct node *new_door = add_door(root, doors);
  add_door_test(new_door, doors, root);
  add_door_test(NULL, doors, root);
  destroy(root);

  new_door = add_door(root, doors);
  remove_door_test(new_door, root);
  remove_door_test(NULL, root);

  return 0;
}

void add_door_test(struct node *elem, struct door *door, struct node *root) {
  if (elem != NULL) {
    struct node *new_door = add_door(elem, door);
    struct node *ptr = find_door(new_door->door_elem.id, root);
    if (ptr == new_door) {
      printf("SUCCESS\n");
    } else if (new_door == NULL || ptr == NULL) {
      printf("FAIL\n");
    }
  } else {
    printf("FAIL\n");
  }
}

void remove_door_test(struct node *elem, struct node *root) {
  if (elem != NULL) {
    struct node *ptr = remove_door(elem, root);
    if (ptr == root) {
      printf("SUCCESS\n");
    }
  } else {
    printf("FAIL\n");
  }
}
