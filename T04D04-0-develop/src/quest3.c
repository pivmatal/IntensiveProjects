#include <stdio.h>

int fib(int a);

int main() {
  float a;
  int valid = scanf("%f", &a);
  int x = (int)a;
  if (x != a || valid != 1) {
    printf("n/a");
    return 0;
  }
  printf("%d", fib(x));
  return 0;
}

int fib(int a) {
  if (a == 1) {
    return 0;
  }
  if (a == 2 || a == 3) {
    return 1;
  }
  int res = fib(a - 1) + fib(a - 2);
  return res;
}
