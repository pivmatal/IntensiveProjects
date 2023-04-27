#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define WIDTH 80
#define HEIGHT 25
#define LIVE_CELL "■"
#define DEAD_CELL " "
#define TRUE 1
#define FALSE 0

int **set_dynamic_matrix(int m, int n);
int **get_coords_neighbors(int cell_x, int cell_y);
int get_count_live_neighbors(int **map, int cell_x, int cell_y);
int get_count_live_cell(int **map);
int check_game_end(int count_live_cell, int **oldmap, int **newmap);
void filling_map(int **map, int m, int n);
void new_generation(int **map, int m, int n);
void input_map(int **map, int m, int n);
void copy_matrix(int **from_matrix, int **to_matrix, int m, int n);
void draw_map(int **map, int m, int n);
void draw_screen(int **map, int live_cell, int generation_count);
void set_speed(int speed);
void clear_screen();
void game_loop();
void init_game(int **map, int m, int n);

int main() {
  game_loop();
  return 0;
}

void game_loop() {
  int **map = set_dynamic_matrix(HEIGHT, WIDTH);
  int **old_map = set_dynamic_matrix(HEIGHT, WIDTH);
  int generation_counter = 0;
  int game_end = FALSE;
  int speed = 1;

  init_game(map, HEIGHT, WIDTH);

  printf("Введите скорость игры:  ");
  printf("\n");
  scanf("%d", &speed);

  while (TRUE) {
    if (game_end == TRUE)
      break;
    int live_cell = get_count_live_cell(map);
    draw_screen(map, live_cell, generation_counter);
    copy_matrix(map, old_map, HEIGHT, WIDTH);

    new_generation(map, HEIGHT, WIDTH);
    generation_counter++;

    game_end = check_game_end(live_cell, map, old_map);
    set_speed(speed);
  }

  free(old_map);
  free(map);
}

void draw_screen(int **map, int live_cell, int generation_count) {
  clear_screen();
  draw_map(map, HEIGHT, WIDTH);
  printf("Generation: %d\n", generation_count);
  printf("Live: %d\n", live_cell);
  printf("Для завершения игры нажмите CTRL + C\n");
}

void input_map(int **map, int m, int n) {
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      char scan;
      scanf("%c", &scan);
      if (scan == '1')
        map[i][j] = 1;
      if (scan == '0')
        map[i][j] = 0;
    }
  }
}

void draw_map(int **map, int m, int n) {
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      if (map[i][j] == 1)
        printf(LIVE_CELL);
      else
        printf(DEAD_CELL);
    }
    printf("\n");
  }
}

int **set_dynamic_matrix(int m, int n) {
  int **matrix = (int **)malloc(m * n * sizeof(int) + m * sizeof(int *));
  int *ptr = (int *)(matrix + m);

  for (int i = 0; i < m; i++) {
    matrix[i] = ptr + n * i;
  }

  return matrix;
}

int **get_coords_neighbors(int cell_x, int cell_y) {
  int **res = set_dynamic_matrix(8, 2);
  int counter = 0;

  for (int i = cell_x - 1; i <= cell_x + 1; i++) {
    for (int j = cell_y - 1; j <= cell_y + 1; j++) {
      if (i == cell_x && j == cell_y) {
        continue;
      }
      res[counter][0] = i;
      res[counter][1] = j;

      counter++;
    }
  }

  for (int i = 0; i < 8; i++) {
    if (res[i][0] == -1)
      res[i][0] = WIDTH - 1;
    if (res[i][0] == WIDTH)
      res[i][0] = 0;
    if (res[i][1] == -1)
      res[i][1] = HEIGHT - 1;
    if (res[i][1] == HEIGHT)
      res[i][1] = 0;
  }

  return res;
}

int get_count_live_neighbors(int **map, int cell_x, int cell_y) {
  int count = 0;
  int **neigbors_coords = get_coords_neighbors(cell_x, cell_y);

  for (int i = 0; i < 8; i++) {
    int x = neigbors_coords[i][0];
    int y = neigbors_coords[i][1];

    if (map[y][x] == 1)
      count++;
  }

  free(neigbors_coords);

  return count;
}

void new_generation(int **map, int m, int n) {
  int **next_day_map = set_dynamic_matrix(HEIGHT, WIDTH);
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      next_day_map[i][j] = 0;
    }
  }

  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      int cell_status = map[i][j];
      int count = get_count_live_neighbors(map, j, i);
      if (cell_status == 0) {
        if (count == 3) {
          next_day_map[i][j] = 1;
        }
      } else {
        if (count == 2 || count == 3) {
          next_day_map[i][j] = 1;
        } else {
          next_day_map[i][j] = 0;
        }
      }
    }
  }
  copy_matrix(next_day_map, map, HEIGHT, WIDTH);
  free(next_day_map);
}

void copy_matrix(int **from_matrix, int **to_matrix, int m, int n) {
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      to_matrix[i][j] = from_matrix[i][j];
    }
  }
}

int get_count_live_cell(int **map) {
  int count = 0;
  for (int i = 0; i < HEIGHT; i++) {
    for (int j = 0; j < WIDTH; j++) {
      if (map[i][j] == 1)
        count++;
    }
  }

  return count;
}

void clear_screen() { printf("\033[H\033[J"); }

int check_game_end(int count_live_cell, int **oldmap, int **newmap) {
  int is_end = FALSE;
  int checker = 0;

  if (count_live_cell == 0)
    is_end = TRUE;
  for (int i = 0; i < HEIGHT; i++) {
    for (int j = 0; j < WIDTH; j++) {
      if (oldmap[i][j] != newmap[i][j])
        checker = 1;
    }
  }
  if (checker == 0)
    is_end = TRUE;

  return is_end;
}

void set_speed(int speed) { usleep(1000000 / speed); }

void init_game(int **map, int m, int n) {
  printf("Enter start position (0 - dead cell, 1 - live cell):\n");
  input_map(map, m, n);
}
