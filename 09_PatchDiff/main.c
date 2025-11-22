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

void print_mat(char **m, size_t sz) {
  for (size_t i = 0; i < sz; ++i) {
    for (size_t j = 0; j < sz; ++j) {
      printf("%c", m[i][j]);
    }
    printf("\n");
  }
}

void init(char **m, size_t sz) {
  for (size_t i = 0; i < sz; ++i) {
    for (size_t j = 0; j < sz; ++j) {
      m[i][j] = ((j % 2 == 0) || (i % 2 == 0)) ? '#' : '.';
    }
  }
}

int dfs(int row, int col, char **visited, int vis_size, char **maze) {
  if (row < 0 || row >= vis_size || col < 0 || col >= vis_size ||
      visited[row][col] == 1) {
    return 0;
  }

  visited[row][col] = 1;
  int seq[] = {0, 1, 2, 3};
  for (size_t i = 0; i < 4; ++i) {
    int tmp = seq[i];
    int randi = rand() % 4;
    seq[i] = seq[randi];
    seq[randi] = tmp;
  }

  for (size_t i = 0; i < 4; ++i) {
    if (seq[i] == 0 && dfs(row + 1, col, visited, vis_size, maze) == 1) {
      maze[2 * row + 2][2 * col + 1] = '.';
    }
    if (seq[i] == 1 && dfs(row, col + 1, visited, vis_size, maze) == 1) {
      maze[2 * row + 1][2 * col + 2] = '.';
    }
    if (seq[i] == 2 && dfs(row - 1, col, visited, vis_size, maze) == 1) {
      maze[2 * row][2 * col + 1] = '.';
    }
    if (seq[i] == 3 && dfs(row, col - 1, visited, vis_size, maze) == 1) {
      maze[2 * row + 1][2 * col] = '.';
    }
  }
  return 1;
}

void create_maze(char **m, size_t sz) {
  char **visited = alloc_matrix(sz);
  for (size_t i = 0; i < sz; ++i) {
    for (size_t j = 0; j < sz; ++j) {
      visited[i][j] = 0;
    }
  }

  dfs(0, 0, visited, sz, m);
  free_matrix(visited, sz);
}

int main() {
  size_t maze_size = MAZE_SIZE;
  size_t vsize = SIZE;
  srand(time(NULL));
  char **maze = alloc_matrix(maze_size);
  init(maze, maze_size);
  create_maze(maze, vsize);
  print_mat(maze, maze_size);
  free_matrix(maze, maze_size);
}
