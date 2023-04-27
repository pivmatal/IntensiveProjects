#include <math.h>
#include <stdio.h>

int del(int a, int b);
int ost(int a, int b);
int npd(int a);

int main() {
  float a;
  int valid = scanf("%f", &a);
  int x = (int)a;
  if (valid != 1 || x == 0 || x != a) {
    printf("n/a");
    return 0;
  }
  x = fabs(x);
  int max = npd(x);
  printf("%d\n", max);

  return 0;
}

int del(int a, int b) {
  int c = 0;
  for (int i = 0; a >= b; i++) {
    a = a - b;
    c++;
  }
  return c;
}

int ost(int a, int b) {
  while (a >= b) {
    a = a - b;
  }
  return a;
}

int npd(int a) {
  int i = 2;
  int maximum;
  if (a == 1) {
    return a;
  }
  while (a != 0) {
    if (ost(a, i) != 0) {
      i = i + 1;
    } else {
      maximum = a;
      a = del(a, i);
      if (a == 1) {
        break;
      }
    }
  }
  return maximum;
}
