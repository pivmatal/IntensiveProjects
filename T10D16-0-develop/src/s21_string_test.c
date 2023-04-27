#include "s21_string.h"
#include <stdio.h>
#include <stdlib.h>

void s21_strlen_test(char *n);
void s21_strcmp_test(char *n, char *m);
void s21_strcpy_test(char *c, char *m);
void s21_strcat_test(char *x, char *y, char *c);
void s21_strchr_test(char *n, char *ch);

int main() {
  char *ch = "l";
  char *ch2 = "w";
  char c[24] = {};
  char *test1 = "school21";
  char *test2 = "school\a21";
  char *test3 = " school21 ";
  char *test4 = "SCHOOL21";
  char *test5 = "         ";
  char *test6 = " ";
  char *test7 = "schooll21";

  s21_strlen_test(test1);
  s21_strlen_test(test2);
  s21_strlen_test(test3);
  s21_strlen_test(test4);
  s21_strlen_test(test5);

  printf("\n");

  s21_strcmp_test(test1, test1);
  s21_strcmp_test(test1, test3);
  s21_strcmp_test(test1, test4);
  s21_strcmp_test(test5, test6);
  s21_strcmp_test(test1, test7);

  printf("\n");

  s21_strcpy_test(c, test4);
  s21_strcpy_test(c, test3);
  s21_strcpy_test(c, test2);
  s21_strcpy_test(c, test1);

  printf("\n");

  s21_strcat_test(test1, test1, c);
  s21_strcat_test(test1, test4, c);
  s21_strcat_test(test1, test3, c);
  s21_strcat_test(test1, test2, c);
  s21_strcat_test(test5, test6, c);

  printf("\n");

  s21_strchr_test(test1, ch);
  s21_strchr_test(test1, ch2);
  s21_strchr_test(test3, ch);
  s21_strchr_test(test1, test5);

  return 0;
}

void s21_strlen_test(char *n) {
  int cout = s21_strlen(n);

  if (cout == 8) {
    printf("%s %d SUCCESS\n", n, cout);
  } else if (cout == 0) {
    printf("%s %d SUCCESS\n", n, cout);
  } else {
    printf("%s %d FAIL\n", n, cout);
  }
}

void s21_strcmp_test(char *n, char *m) {
  int cout = s21_strcmp(n, m);

  if (cout == 0 && (s21_strlen(n) == s21_strlen(m))) {
    printf("%s %s %d SUCCESS\n", n, m, cout);
  } else if (cout == 0 && (s21_strlen(n) != s21_strlen(m))) {
    printf("%s %s %d FAIL\n", n, m, cout);
  }

  if (cout == 1 && (s21_strlen(n) > s21_strlen(m))) {
    printf("%s %s %d SUCCESS\n", n, m, cout);
  } else if (cout == 1 && ((s21_strlen(n) == s21_strlen(m)) ||
                           (s21_strlen(n) < s21_strlen(m)))) {
    printf("%s %s %d FAIL\n", n, m, cout);
  }

  if (cout == -1 && (s21_strlen(n) < s21_strlen(m))) {
    printf("%s %s %d SUCCESS\n", n, m, cout);
  } else if (cout == -1 && ((s21_strlen(n) == s21_strlen(m)) ||
                            (s21_strlen(n) > s21_strlen(m)))) {
    printf("%s %s %d FAIL\n", n, m, cout);
  }
}

void s21_strcpy_test(char *c, char *m) {
  int b = 0;
  s21_strcpy(c, m);

  for (int cout = 0; m[cout] != '\0'; cout++) {
    if (c[cout] == m[cout]) {
      b++;
    }
  }

  if (b == 8) {
    printf("%s %s %d SUCCESS\n", m, c, b);
  }

  if (b != 8) {
    printf("%s %s %d FAIL\n", m, c, b);
  }
}

void s21_strcat_test(char *x, char *y, char *c) {
  s21_strcat(x, y, c);

  if (s21_strlen(c) == 16) {
    printf("%s %s %s SUCCESS\n", x, y, c);
  }

  if (s21_strlen(c) != 16) {
    printf("%s %s %s FAIL\n", x, y, c);
  }
}

void s21_strchr_test(char *n, char *ch) {
  int x = s21_strchr(n, ch);
  if (x == 5) {
    printf("%s %s %d SUCCESS\n", n, ch, x);
  } else {
    printf("%s %s %d FAIL\n", n, ch, x);
  }
}
