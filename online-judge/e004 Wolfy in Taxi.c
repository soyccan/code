#include <stdio.h>
#include <tgmath.h>

int main() {
  float distance;
  scanf("%f", &distance);
  if (distance > 10000)
    puts("Sleeping in school");
  else if (distance <= 1500)
    puts("70");
  else 
    printf("%g\n", 70 + ceil((distance-1500)/500)*5);

  return 0;
}