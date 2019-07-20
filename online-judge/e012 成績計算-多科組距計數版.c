#include <stdio.h>
#include <stdlib.h>

int main() {
  int** groups;
  int student_count, subject_count;
  int full_mark = 100;
  int group_count = 10;
  int interval = full_mark / group_count;

  scanf("%d %d", &student_count, &subject_count);
  groups = calloc(group_count, sizeof *groups);
  for (int i=0; i<group_count; i++) {
    groups[i] = calloc(subject_count, sizeof *groups[i]);
  }

  for (int i=0; i<student_count; i++) {
    for (int j=0; j<subject_count; j++) {
      int score;
      scanf("%d", &score);
      if (score == full_mark)
        score--;
      groups[score/interval][j]++;
    }
  }

  for (int i=group_count-1; i>=0; i--) {
    for (int j=0; j<subject_count; j++) {
      printf("%d ", groups[i][j]);
    }
    putchar('\n');
  }

  return 0;
}