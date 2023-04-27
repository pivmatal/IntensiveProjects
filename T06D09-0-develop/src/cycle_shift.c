
#include <stdio.h>
#define NMAX 10

int input(int *buffer, int *length, int *sdvig);
void output(int *buffer, int *length);
int shift(int *buffer, int *length, int *sdvig);
int review(int *n);

int main() {
  int data[NMAX] = {4, 3, 9, 0, 1, 2, 0, 2, 7, -1};
  int sdvig;
  int n;
  int valid = input(data, &n, &sdvig);
  if (valid != 1) {
    shift(data, &n, &sdvig);
    output(data, &n);
  } else {
    printf("n/a");
  }
  return 0;
}

int input(int *buffer, int *length, int *sdvig) {
  if (review(length) == 1 && *length != 0 && *length <= NMAX) {
    for (int *p = buffer; p - buffer < *length; p++) {
      if (review(p) == 1) {
      } else {
        return 1;
      }
    }
    review(sdvig);
  } else {
    return 1;
  }
  return 0;
}

int review(int *n) {
  int rev = scanf("%d", n);
  if (rev == 1) {
    return 1;
  } else {
  }
  return 0;
}

void output(int *data, int *n) {
  for (int i = 0; i < *n; i++) {
    printf("%d ", data[i]);
  }
}

int shift(int *data, int *n, int *sdvig) {
  if (*sdvig >= 0) {
    for (int i = 0; i < *sdvig; ++i) {
      int tmp = data[0];
      for (int i = 0; i < *n - 1; ++i) {
        data[i] = data[i + 1];
      }
      data[*n - 1] = tmp;
    }
  }
  if (*sdvig < 0) {
    *sdvig = *sdvig * -1;
    for (int i = 0; i < *sdvig; ++i) {
      int tmp2 = data[*n - 1];
      for (int i = *n - 1; i > 0; i--) {
        data[i] = data[i - 1];
      }
      data[0] = tmp2;
    }
  }
  return 0;
}
