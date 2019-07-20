#include <stdio.h>

int main() {
  int n;
  scanf("%d", &n);
  int mid = n - 1;
  for (int i=0; i<n; i++) {
    for (int j=0; j<mid-i; j++) {
      printf("　");
    }
    for (; j<=mid+i; j++) {
      printf("＊");
    }
    putchar('\n');
  }

  return 0;
}