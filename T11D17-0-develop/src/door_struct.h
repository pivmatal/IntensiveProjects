#ifndef DOOR_STRUCT
#define DOOR_STRUCT

struct door {
  int id;
  int status;
};

void initialize_doors(struct door *doors);
void output(struct door *doors);
void sort(struct door *doors);
void zeroing(struct door *doors);

#endif
