#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 6
#define MAZE_SIZE (SIZE * 2 + 1)

char **alloc_matrix(size_t sz) {
  char **mat = (char **)calloc(sz, sizeof(char *));
  for (size_t i = 0; i < sz; ++i) {
    mat[i] = (char *)calloc(sz, sizeof(char));
  }
  return mat;
}

void free_matrix(char **mat, size_t sz) {
  for (size_t i = 0; i < sz; ++i) {
    free(mat[i]);
  }
  free(mat);
}

void print_mat(char **m) {
  for (int i = 0; i < MAZE_SIZE; ++i) {
    for (int j = 0; j < MAZE_SIZE; ++j) {
      printf("%c", m[i][j]);
    }
    printf("\n");
  }
}

void init(char **m) {
  for (int i = 0; i < MAZE_SIZE; ++i) {
    for (int j = 0; j < MAZE_SIZE; ++j) {
      m[i][j] = ((j % 2 == 0) || (i % 2 == 0)) ? '#' : '.';
    }
  }
}

int dfs(int row, int col, char **visited, char **m) {
  if (row < 0 || row >= SIZE || col < 0 || col >= SIZE ||
      visited[row][col] == 1) {
    return 0;
  }

  visited[row][col] = 1;
  int seq[] = {0, 1, 2, 3};
  for (int i = 0; i < 4; ++i) {
    int tmp = seq[i];
    int randi = rand() % 4;
    seq[i] = seq[randi];
    seq[randi] = tmp;
  }

  for (int i = 0; i < 4; ++i) {
    if (seq[i] == 0 && dfs(row + 1, col, visited, m) == 1) {
      m[2 * row + 2][2 * col + 1] = '.';
    }
    if (seq[i] == 1 && dfs(row, col + 1, visited, m)) {
      m[2 * row + 1][2 * col + 2] = '.';
    }
    if (seq[i] == 2 && dfs(row - 1, col, visited, m)) {
      m[2 * row][2 * col + 1] = '.';
    }
    if (seq[i] == 3 && dfs(row, col - 1, visited, m)) {
      m[2 * row + 1][2 * col] = '.';
    }
  }
  return 1;
}

void create_maze(char **m) {
  char **visited = alloc_matrix(SIZE);
  for (int i = 0; i < SIZE; ++i) {
    for (int j = 0; j < SIZE; ++j) {
      visited[i][j] = 0;
    }
  }

  dfs(0, 0, visited, m);
  free_matrix(visited, SIZE);
}

int main() {
  srand(time(NULL));
  char **maze = alloc_matrix(MAZE_SIZE);
  init(maze);
  create_maze(maze);
  print_mat(maze);
  free_matrix(maze, MAZE_SIZE);
}
