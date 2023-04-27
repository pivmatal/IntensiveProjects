/*------------------------------------
        Здравствуй, человек!
        Чтобы получить ключ
        поработай с комментариями.
-------------------------------------*/

#include <stdio.h>
#define NMAX 10

int input(int *buffer, int *length);
void output(int *buffer, int length, int i);
int sum_numbers(int *buffer, int *length);
int find_numbers(int *buffer, int *length, int summa, int *buffer2);
int review(int *n);

int main() {
  int summa;
  int data[NMAX], data2[NMAX];
  int n;
  int valid = input(data, &n);
  if (valid != 1) {
    summa = sum_numbers(data, &n);
    if (summa != 0) {
      int cout = find_numbers(data, &n, summa, data2);
      output(data2, summa, cout);
    } else {
      printf("n/a");
    }
  } else {
    printf("n/a");
  }

  return 0;
}

/*------------------------------------
        Функция должна находить
        сумму четных элементов
        с 0-й позиции.
-------------------------------------*/
int sum_numbers(int *buffer, int *length) {
  int sum = 0;
  for (int i = 0; i < *length; i++) {
    if (buffer[i] != 0) {
      if (buffer[i] % 2 == 0) {
        sum = sum + buffer[i];
      }
    } else {
      sum = sum + 0;
    }
  }
  return sum;
}
/*------------------------------------
        Функция должна находить
        все элементы, на которые нацело
        делится переданное число и
        записывает их в выходной массив.
-------------------------------------*/
int find_numbers(int *buffer, int *length, int summa, int *buffer2) {
  int cout = 0;
  for (int i = 0; i < *length; i++) {
    if (buffer[i] != 0) {
      if (summa % buffer[i] == 0) {
        buffer2[cout] = buffer[i];
        cout++;
      }
    } else {
      cout = cout + 0;
    }
  }
  return cout;
}

int input(int *buffer, int *length) {
  if (review(length) == 1 && *length != 0 && *length <= NMAX) {
    for (int *p = buffer; p - buffer < *length; p++) {
      if (review(p) == 1) {
      } else {
        return 1;
      }
    }
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
    return 0;
  }
}

void output(int *buffer, int summa, int cout) {
  printf("%d\n", summa);
  for (int i = 0; i < cout; i++) {
    printf("%d ", buffer[i]);
  }
}
