#include <stdio.h>
#include <stdlib.h>

void border(int width) {
  /* width of two for example: +---+---+ */
  for (; width>0; width--) {
    printf("+---");
  }
  printf("+\n");
}

void magic_square(int** square, int length) {
  // only for odd numbers
  if (length % 2 == 0)
    return;

  // start from the bottom middle
  int row = length - 1;
  int col = length / 2;

  for (int i=1; i<=length*length; i++) {
    square[row][col] = i;

    int _row = (row + 1) % length; // go down
    int _col = (col + 1) % length; // go right

    if (square[_row][_col] == 0) {
      row = _row;
      col = _col;
    } else {
      // go up
      // plus length to avoid negative
      row = (row + length - 1) % length;
    }
  }
}

int** matrix(int height, int width) {
  int** matrix = calloc(height, sizeof(int*));
  for (int i=0; i<height; i++) {
    matrix[i] = calloc(width, sizeof(int));
  }
  return matrix;
}

int main() {
  int** square;
  int length;

  scanf("%d", &length);
  square = matrix(length, length);
  magic_square(square, length);

  for (int i=0; i<length; i++) {
    border(length);
    for (int j=0; j<length; j++) {
      printf("|%3d", square[i][j]);
    }
    printf("|\n");
  }
  border(length);

  return 0;
}