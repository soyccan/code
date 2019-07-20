#include <stdio.h>
#include <stdlib.h>


int ascend(const void* x, const void* y) {
  return *(int*)x - *(int*)y;
}

int main() {
  int count;
  scanf("%d", &count);

  for (; count>0; count--) {
    int len;
    scanf("%d", &len);

    int seq[len];
    for (int i=0; i<len; i++) {
      scanf("%d", &seq[i]);
    }

    qsort(seq, len, sizeof(int), ascend);

    if (len % 2 == 0)
      printf("%g\n", (float) (seq[len/2-1]+seq[len/2])/2);
    else
      printf("%d\n", seq[len/2]);
  }

  return 0;
}