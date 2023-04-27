#include "s21_string.h"
#include <stdio.h>

int s21_strlen(const char *n) {
  int cout = 0;
  for (; *(n + cout); cout++) {
  }
  return cout;
}

int s21_strcmp(const char *n, const char *m) {
  int flag;
  int coutn = 0;
  int coutm = 0;
  for (; *(n + coutn); coutn++) {
  }

  for (; *(m + coutm); coutm++) {
  }

  if (coutm == coutn) {
    flag = 0;
  } else if (coutn > coutm) {
    flag = 1;
  } else {
    flag = -1;
  }
  return flag;
}

void s21_strcpy(char *n, const char *m) {
  for (int cout = 0; m[cout] != '\0'; cout++) {
    n[cout] = m[cout];
    n[cout + 1] = '\0';
  }
}

void s21_strcat(char *b, const char *m, char *res) {
  int x = s21_strlen(b);
  for (int cout = 0; cout < 8; cout++) {
    res[cout] = b[cout];
  }

  for (int cout = 0; m[cout] != '\0'; cout++) {
    res[cout + x] = m[cout];
  }
}

int s21_strchr(const char *n, const char *ch) {
  int y = 0;
  for (int cout = 0; n[cout] != '\0'; cout++) {
    if (n[cout] == *ch) {
      y = cout;
      break;
    }
  }
  return y;
}
