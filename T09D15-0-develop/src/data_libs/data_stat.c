#include "data_stat.h"
#include <math.h>

double max(double *data, int n) {
  double max = data[0];
  for (int i = 0; n > i; i++) {
    if (data[i] > max) {
      max = data[i];
    }
  }
  return max;
}

double min(double *data, int n) {
  double min = data[0];
  for (int i = 0; n > i; i++) {
    if (data[i] < min) {
      min = data[i];
    }
  }
  return min;
}

double mean(double *data, int n) {
  double sum = 0;
  for (int i = 0; n > i; i++) {
    sum = data[i] + sum;
  }
  double mean = sum / n;
  return mean;
}

double variance(double *data, int n) {
  double sum = 0, sred, summa = 0;
  for (int i = 0; i < n; i++) {
    sum = data[i] + sum;
  }
  sred = sum / n;
  for (int i = 0; i < n; i++) {
    summa = pow((data[i] - sred), 2) + summa;
  }
  double variance = summa / n;
  return variance;
}

double sort(double *data, int n) {
  for (int i = 1; i < n; i++) {
    for (int i = 1; i < n; i++) {
      if (data[i] < data[i - 1]) {
        int c = data[i];
        data[i] = data[i - 1];
        data[i - 1] = c;
      }
    }
  }
  return 0;
}
