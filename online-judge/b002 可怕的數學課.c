#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool belong(int* set, int size, int element) {
  /* binary search, require a sorted set */

  int left = 0;
  int right = size;

  while (left <= right) {
    int middle = (left + right) / 2;
    if (element < set[middle]) {
      right = middle - 1;
    } else if (element > set[middle]) {
      left = middle + 1;
    } else {
      return true;
    }
  }

  return false;
}

int main() {
  int element_count, query_count;
  int inclusion = 0;
  int* set;

  scanf("%d", &element_count);
  set = calloc(element_count, sizeof *set);
  for (int i=0; i<element_count; i++) {
    int element;
    scanf("%d", &element);
    set[i] = element;
  }

  scanf("%d", &query_count);
  for (int i=0; i<query_count; i++) {
    int query;
    scanf("%d", &query);
    if (belong(set, element_count, query))
      inclusion++;
  }

  printf("%d\n", inclusion);
  printf("%d\n", query_count - inclusion);

  return 0;
}