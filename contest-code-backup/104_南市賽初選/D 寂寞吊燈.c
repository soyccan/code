#include <stdio.h>
#include <stdlib.h> // abs
#include <tgmath.h> // fmin pow sqrt
#include <limits.h> // LLONG_MAX

typedef struct {
  int x, y;
} Point;

long long distance_squared(Point p, Point q) {
  return pow(p.x-q.x, 2) + pow(p.y-q.y, 2);
}

int main() {
  int amount;
  scanf("%d", &amount);

  Point points[amount];
  long long min = LLONG_MAX;

  for (int i=0; i<amount; i++) {
    scanf("%d %d", &points[i].x, &points[i].y);

    for (int j=0; j<i; j++) {
      if (abs(points[i].x - points[j].x) < min
          && abs(points[i].y - points[j].y) < min) {
        min = fmin(min, distance_squared(points[i], points[j]));
      }
    }
  }

  printf("%.6f\n", sqrt(min));

  return 0;
}