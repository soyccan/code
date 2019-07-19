#include <bits/stdc++.h>
using namespace std;

int calc(int n) {
  if (n / 10 == 0)
    return n;
  else {
    int sum = 0;
    while (n != 0) {
      sum += n % 10;
      n /= 10;
    }
    return calc(sum);
  }
}

int main() {
  string a, b;
  while (getline(cin, a) && getline(cin, b)) {
    double sa = 0;
    for (char c : a)
      if (isalpha(c))
        sa += tolower(c) - 'a' + 1;
    sa = calc(sa);

    double sb = 0;
    for (char c : b)
      if (isalpha(c))
        sb += tolower(c) - 'a' + 1;
    sb = calc(sb);

    printf("%.2f %%\n", min(sa, sb)/max(sa, sb)*100);
  }

  return 0;
}