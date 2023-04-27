#include "data_io.h"
#include <stdio.h>

void input(double *data, int n) {
  double x;
  for (int i = 0; n > i; i++) {
    scanf("%lf", &x);
    data[i] = x;
  }
}

void output(double *data, int n) {
  for (int i = 0; n > i; i++) {
    printf("%.2lf ", data[i]);
  }
}
