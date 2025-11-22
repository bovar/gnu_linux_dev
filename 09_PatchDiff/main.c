#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 6
#define MAZE_SIZE (SIZE * 2 + 1)

char maze[MAZE_SIZE][MAZE_SIZE];

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
      maze[i][j] = ((j % 2 == 0) || (i % 2 == 0)) ? '#' : '.';
    }
  }
}

int dfs(int row, int col, char visited[SIZE][SIZE]) {
  if (visited[row][col] == 1 || row < 0 || row >= SIZE || col < 0 ||
      col >= SIZE) {
    return 0;
  }

  visited[row][col] = 1;
  int r = rand() % 4;
  for (int i = 0; i < 4; ++i) {
    if ((r + i) % 4 == 0 && dfs(row + 1, col, visited) == 1) {
      maze[2 * row + 2][2 * col + 1] = '.';
    }
    if ((r + i) % 4 == 1 && dfs(row, col + 1, visited)) {
      maze[2 * row + 1][2 * col + 2] = '.';
    }
    if ((r + i) % 4 == 2 && dfs(row - 1, col, visited)) {
      maze[2 * row][2 * col + 1] = '.';
    }
    if ((r + i) % 4 == 3 && dfs(row, col - 1, visited)) {
      maze[2 * row + 1][2 * col] = '.';
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

  dfs(0, 0, visited);

  return;
}

int main() {
  srand(time(NULL));
  init(maze);
  create_maze(maze);
  print_mat(maze);
}
