#include "../data_libs/data_io.h"
#include "data_process.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
  double *data;
  int n;

  // Don`t forget to allocate memory !
  scanf("%d", &n);
  data = malloc(sizeof(double) * n);
  input(data, n);

  if (normalization(data, n))
    output(data, n);
  else
    printf("ERROR");

  free(data);
  return 0;
}
