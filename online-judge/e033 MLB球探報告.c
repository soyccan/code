#include <stdio.h>

int main() {
  float innings;
  int strikeouts, earnedruns;
  scanf("%f %d %d", &innings, &strikeouts, &earnedruns);

  float k9 = (float) strikeouts / innings * 9;
  float era = (float) earnedruns / innings * 9;
  printf("%.2f\n%.2f\n", k9, era);

  if (k9 >= 9 || era <= 3)
    puts("A");
  else if (k9 >= 6 || era <= 4.5)
    puts("B");
  else
    puts("C");

  return 0;
}