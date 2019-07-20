#include <stdio.h>

int main() {
  int pts, reb, ast, stl, blk, fga, fgm, fta, ftm, to, gp;
  float eff;
  /* points, rebounds, assists, steals, blocks
     field goals attempted, field goals made
     free throws attempted, free throws made
     turnovers, games played, efficiency */

  scanf("%d %d %d %d %d %d %d %d %d %d %d",
        &pts, &reb, &ast, &stl, &blk, &fga, &fgm, &fta, &ftm, &to, &gp);
  eff = (float) (pts + reb + ast + stl + blk - (fga - fgm) - (fta - ftm) - to) / gp;
  printf("%.2f\n", eff);

  if (eff >= 30)
    puts("$10M");
  else if (eff >= 25)
    puts("$7M");
  else if (eff >= 20)
    puts("$3M");
  else
    puts("$1M");

  return 0;
}