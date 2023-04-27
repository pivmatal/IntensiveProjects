#include "door_struct.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DOORS_COUNT 15
#define MAX_ID_SEED 10000

int main() {
  struct door doors[DOORS_COUNT];
  initialize_doors(doors);
  sort(doors);
  zeroing(doors);
  output(doors);

  return 0;
}

// Doors initialization function
// ATTENTION!!!
// DO NOT CHANGE!
void initialize_doors(struct door *doors) {
  srand(time(0));

  int seed = rand() % MAX_ID_SEED;
  for (int i = 0; i < DOORS_COUNT; i++) {
    doors[i].id = (i + seed) % DOORS_COUNT;
    doors[i].status = rand() % 2;
  }
}

void output(struct door *doors) {
  for (int i = 0; i < DOORS_COUNT; i++) {
    printf("%d, %d\n", doors[i].id, doors[i].status);
  }
}

void sort(struct door *doors) {
  for (int i = 1; i < DOORS_COUNT; i++) {
    for (int j = 1; j < DOORS_COUNT; j++) {
      if (doors[j].id < doors[j - 1].id) {
        int c = doors[j].id;
        doors[j].id = doors[j - 1].id;
        doors[j - 1].id = c;
      }
    }
  }
}

void zeroing(struct door *doors) {
  for (int i = 0; i < DOORS_COUNT; i++) {
    doors[i].status = 0;
  }
}
