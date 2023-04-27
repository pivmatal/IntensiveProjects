  // I WANT TO PLAY WITH YOU
  //         YOUR FRIEND, AI
#include <stdio.h>
#define home()                                                                 \
printf(ESC "[H")  // Move cursor to the indicated row, column (origin at 1,1)
#define clrscr() printf(ESC "[2J")  // lear the screen, move to (1,1)
#define gotoxy(x, y) printf(ESC "[%d;%dH", y, x);
#define ESC "\033"
#define StartpozitionX 40
#define StartpozitionY 12

int field(char spaces, int x, int y, int yL, int yR, int pointOne,
          int pointTwo);
int table(char spaces, int pointOne, int pointTwo);

int main() {
  int x = 40, y = 15;
  int yL = 15, yR = 15;
  int pointOne = 0, pointTwo = 0;
  int speedX = 3, speedY = 1;
  char spaces = ' ';
  char skip_action;

  while (1) {
    scanf("%c", &skip_action);
    if (skip_action == ' ' || skip_action == 'z' || skip_action == 'a' ||
        skip_action == 'k' || skip_action == 'm') {
      home();
      clrscr();

      //  ракетки
      if (skip_action == 'a') {
        if ((yL != 7)) {  //  вместо 0 и 12 нужно поставить границы поля
          yL--;
        }
      }
      if (skip_action == 'z') {
        if ((yL != 23)) {
          yL++;
        }
      }

      if (skip_action == 'k') {
        if ((yR != 7)) {
          yR--;
        }
      }
      if (skip_action == 'm') {
        if ((yR != 23)) {
          yR++;
        }
      }
      field(spaces, x, y, yL, yR, pointOne, pointTwo);
      //  движение шарика
      if (x <= 1) {
        pointTwo++;
        x = StartpozitionX;
        y = StartpozitionY;
        speedX = speedX * -1;

        if (pointTwo == 21) {
          printf("Игрок 2 поздравляем, ты выиграл");
          return 0;
        }
      }
      if (x >= 80) {
        pointOne++;
        x = StartpozitionX;
        y = StartpozitionY;
        speedX = speedX * -1;
        if (pointOne == 21) {
          printf("Игрок 1 поздравляем, ты выиграл");
          return 0;
        }
      }


      if (y == 6 || y == 24) {
        speedY = -speedY;
      }
      if ((y == yR + 1 || y == yR - 1 || y == yR) && (x + 1 == 68)) {
        speedX = -speedX;
      }

      if ((y == yL + 1 || y == yL - 1 || y == yL) && (x - 1 == 12)) {
        speedX = -speedX;
      }

      x = x + speedX;
      y = y + speedY;
    }
  }

  return 0;
}

int field(char spaces, int x, int y, int yL, int yR, int pointOne,
          int pointTwo) {
  table(spaces, pointOne, pointTwo);
  int upper_bound = 0;  //  переменная для верхней границы поля
  int lower_bound;  //  переменная для нижней границы поля
  for (upper_bound = 0; upper_bound < 79; upper_bound++) {
    if (upper_bound == 0) {
      printf(" -");
    } else if (upper_bound < 78) {
      printf("-");
    } else {
      printf(" \n");
    }
  }
  for (int i = 0; i < 25; i++) {
    for (int j = 0; j < 80; j++) {
      if ((j == 1 && (i == yL - 1 || i == yL || i == yL + 1)) ||
          (j == 78 && (i == yR - 1 || i == yR || i == yR + 1))) {
        gotoxy(12, yL - 1);
        printf("|");
        gotoxy(12, yL);
        printf("|");
        gotoxy(12, yL + 1);
        printf("|");

        gotoxy(68, yR - 1);
        printf("|");
        gotoxy(68, yR);
        printf("|");
        gotoxy(68, yR + 1);
        printf("|");
      }
    }
  }

  gotoxy(x, y);
  printf("@");

  for (lower_bound = 0; lower_bound < 79; lower_bound++) {
    if (lower_bound == 0) {
      for (int i = 0; i < 25 - y; i++) {
        printf("\n");
      }
      printf(" -");
    } else if (lower_bound < 78) {
      printf("-");
    } else {
      printf(" \n");
    }
  }

  return 0;
}

int table(char spaces, int pointOne, int pointTwo) {
  int upper_bound_table = 0;
  for (upper_bound_table = 0; upper_bound_table < 79; upper_bound_table++) {
    if (upper_bound_table == 0 && (pointOne < 21 || pointTwo < 21)) {
      printf(" -");
    } else if (upper_bound_table < 78) {
      printf("-");
    } else {
      printf("\n|%78c|\n|   Игрок 1: %02d%50cИгрок 2: %02d   |\n|%78c|\n",
             spaces, pointOne, spaces, pointTwo, spaces);
    }
  }
  return 0;
}
