#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#ifndef _STDBOOL_H
# define bool _Bool
# define true 1
# define false 0
#endif


bool divide(char* buffer, int dividend, int divisor) {
  if (dividend == 0 || divisor == 0 || divisor == 1) {
    return false;
  }

  while (dividend != 1) {
    if (dividend % divisor != 0) {
      return false;
    }
    sprintf(buffer+strlen(buffer), "%d ", dividend);
    dividend /= divisor;
  }

  sprintf(buffer+strlen(buffer), "1"); // last item is always one
  return true;
}

int main() {
  int dividend, divisor;
  while (scanf("%d %d", &dividend, &divisor) == 2) {
    char output[100] = "";
    puts(divide(output, dividend, divisor) ? output : "Boring!");
  }

  return 0;
}