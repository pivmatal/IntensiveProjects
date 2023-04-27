#include <math.h>
#include <stdio.h>

int main() {
  double pi = -M_PI, i;
  double a, b, d;
  i = (2 * M_PI) / 41;

  for (int t = 1; t <= 42; t++) {
    a = 1 / (1 + (pi * pi));
    b = sqrt(sqrt(1 + 4 * pi * pi) - (pi * pi) - 1);
    d = 1 / (pi * pi);
    if (isnan(b) != 0) {
      printf("%.7f | %.7f | - | %.7f  \n", pi, a, d);
    } else {
      printf("%.7f | %.7f | %.7f | %.7f  \n", pi, a, b, d);
    }
    pi = pi + i;
  }
  return 0;
}
