#include <stdio.h>

int min(int x, int y) {
  return x < y ? x : y;
}

int main() {
  int duration; /* second */
  scanf("%d", &duration);

  if (duration < 0 || duration > 10000) {
    puts("Get out!!");
  } else if (duration > 1000) {
    puts("RIP!!");
  } else {
    float hurt = 2.1 * min(120, duration);

    if (duration > 120)
      hurt += 3.02 * (min(330, duration)-120);
    if (duration > 330)
      hurt += 4.39 * (min(500, duration)-330);
    if (duration > 500)
      hurt += 4.97 * (min(700, duration)-500);
    if (duration > 700)
      hurt += 5.63 * (duration-700);

    printf("%g\n", hurt);
  }

  return 0;
}