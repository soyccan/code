#include <stdio.h>

void border(int width) {
  /* width of two for example: +---+---+ */
  for (; width>0; width--) {
    printf("+---");
  }
  printf("+\n");
}

int main() {
  int num = 1;
  int col, row;

  scanf("%d %d", &row, &col);

  for (int i=0; i<row; i++) {
    border(col);
    for (int j=0; j<col; j++) {
      if ((i + j) % 2 == 0) {
        // on diagonal
        printf("|%3d", num++);
      } else {
        printf("|  0");
      }
    }
    printf("|\n");
  }
  border(col);

  return 0;
}