#include <stdio.h>
#include <stdbool.h>

int main() {
  int len;
  while (scanf("%d", &len) == 1) {
    bool unique = true;
    int first;
    scanf("%d", &first);

    for (len--; len>0; len--) {
      int this;
      scanf("%d", &this);
      if (this != first) {
        unique = false;
      }
    }

    puts(unique ? "Yes" : "No");
  }

  return 0;
}