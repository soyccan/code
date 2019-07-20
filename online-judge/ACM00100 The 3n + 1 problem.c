#include <stdio.h>

int max(int x, int y) {
  return x > y ? x : y;
}

int min(int x, int y) {
  return x < y ? x : y;
}

int cycle_length(int n) {
  int count = 0;
  while (n > 1) {
    if (n % 2 == 1) {
      n = 3*n + 1;
    } else {
      n /= 2;
    }
    count++;
  }
  return count + 1;
}

int main() {
  int begin, end;
  while (scanf("%d %d", &begin, &end) == 2) {
    int max_length = 0;
    for (int i = min(begin, end); i <= max(begin, end); i++) {
      max_length = max(max_length, cycle_length(i));
    }
    printf("%d %d %d\n", begin, end, max_length);
  }

  return 0;
}