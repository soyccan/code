#include <math.h>
#include <stdio.h>


double max(double x, double y) {
  return x > y ? x : y;
}

int main() {
  double a, b, c;
  scanf("%lf %lf %lf", &a, &b, &c);
  double longest = max(max(a, b), c);

  if (a + b + c - longest <= longest) {
    puts("illegal");
    puts("unavailable");
  } else {
    double discriminant = pow(a, 2) + pow(b, 2) + pow(c, 2) - 2*pow(longest, 2);

    if (discriminant == 0)
      puts("right");
    else if (discriminant > 0)
      puts("acute");
    else if (discriminant < 0)
      puts("obtuse");

    double p = (a + b + c) / 2;
    printf("%g\n", sqrt(p * (p-a) * (p-b) * (p-c)));
  }

  return 0;
}