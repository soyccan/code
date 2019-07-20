#include <stdio.h>
#include <math.h>

// int check(int seq[], int len) {
//   int front[len], back[len];
//   for (int i=0; i<len; i++) {
//     if ()
//   }

//   int max_len = 1;
//     for (int j=1; j<=i; j++) {
//       if (seq[i-j] >= seq[i-j+1] || seq[i+j-1] <= seq[i+j]) {
//         break;
//       }
//       max_len = fmax(max_len, 2*j + 1);
//     }
//   return max_len;
// }

int main() {
  int len;
  while (scanf("%d", &len) == 1) {
    int seq[len], increasing[len], decreasing[len];
    int increasing_count = 0;
    int decreasing_count = 0;

    for (int i=0; i<len; i++) {
      scanf("%d", &seq[i]);
      if (increasing_count == 0 || seq[i] > increasing[increasing_count])
        increasing[increasing_count++] = seq[i];
      printf("%d %d\n", seq[i], increasing[increasing_count]);
    }

    printf("%d\n", increasing_count);

    // printf("%d\n", check(seq, len));
    // if (len % 2 == 0)
    //   printf("%g\n", (float) (seq[len/2-1]+seq[len/2])/2);
    // else
    //   printf("%d\n", seq[len/2]);
  }

  return 0;
}