#include <stdio.h>

int input(double *data, int *n);
void output(double *a, int *n);
double review(double *n);
int sort(double *data, int *n);

int main() {
  double data[10];
  int n = 10;

  if (input(data, &n) == 1) {
    printf("n/a");
    return 0;
  }
  sort(data, &n);
  output(data, &n);
  return 0;
}

int input(double *data, int *n) {
  for (double *p = data; p - data < *n; p++) {
    if (review(p) == 1) {
    } else {
      return 1;
    }
  }
  return 0;
}

double review(double *n) {
  int rev = scanf("%lf", n);
  int x = (int)*n;
  if (x == *n && rev == 1) {
    return 1;
  } else {
    return 0;
  }
}

int sort(double *data, int *n) {
  for (int i = 1; i < *n; i++) {
    for (int i = 1; i < *n; i++) {
      if (data[i] < data[i - 1]) {
        int c = data[i];
        data[i] = data[i - 1];
        data[i - 1] = c;
      }
    }
  }
  return 0;
}

void output(double *data, int *n) {
  for (int i = 0; i < *n; i++) {
    data[i] = (int)data[i];
    printf("%.0lf ", data[i]);
  }
}
