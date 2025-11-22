#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 6
#define MAZE_SIZE (SIZE * 2 + 1)

void print_mat(char m[MAZE_SIZE][MAZE_SIZE]) {
  for (int i = 0; i < MAZE_SIZE; ++i) {
    for (int j = 0; j < MAZE_SIZE; ++j) {
      printf("%c", m[i][j]);
    }
    printf("\n");
  }
}

void init(char m[MAZE_SIZE][MAZE_SIZE]) {
  for (int i = 0; i < MAZE_SIZE; ++i) {
    for (int j = 0; j < MAZE_SIZE; ++j) {
      m[i][j] = ((j % 2 == 0) || (i % 2 == 0)) ? '#' : '.';
    }
  }
}

int dfs(int row, int col, char visited[SIZE][SIZE],
        char m[MAZE_SIZE][MAZE_SIZE]) {
  if (visited[row][col] == 1 || row < 0 || row >= SIZE || col < 0 ||
      col >= SIZE) {
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

void create_maze(char m[MAZE_SIZE][MAZE_SIZE]) {
  char visited[SIZE][SIZE];
  for (int i = 0; i < SIZE; ++i) {
    for (int j = 0; j < SIZE; ++j) {
      visited[i][j] = 0;
    }
  }

  dfs(0, 0, visited, m);

  return;
}

int main() {
  srand(time(NULL));
  char maze[MAZE_SIZE][MAZE_SIZE];

  init(maze);
  create_maze(maze);
  print_mat(maze);
}
