#include <bits/stdc++.h>
using namespace std;

int main() {
  string t;
  while (cin >> t && t != "0:00") {
    if (t.size() != 5)
      t.insert(0, "0");
    int h = (t[0]-'0')*10 + (t[1]-'0');
    int m = (t[3]-'0')*10 + (t[4]-'0');
    double ang = abs(30*h - 5.5*m);
    if (ang > 180) ang = 360 - ang;
    printf("%.3f\n", ang);
  }

  return 0;
}
