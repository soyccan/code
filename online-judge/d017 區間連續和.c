#include <stdio.h>
#include <stdlib.h>

int main() {
  int length;
  while (scanf("%d", &length) == 1) {
    int* sum = calloc(length+1, sizeof(int));

    for (int i=1; i<=length; i++) {
      int n;
      scanf("%d", &n);
      sum[i] = sum[i-1] + n;
    }

    int query_count;
    scanf("%d", &query_count);
    for (; query_count>0; query_count--) {
      int start, end;
      scanf("%d %d", &start, &end);

      if (start > end) {
        int tmp = start;
        start = end;
        end = tmp;
      }

      printf("%d\n", sum[end]-sum[start-1]);
    }
  }

  return 0;
}