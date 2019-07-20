#include <bits/stdc++.h>
using namespace std;

int main() {
  int run = 0;
  while (1) {
    run++;
    int n, m;
    string ans, out;

    cin >> n;
    cin.ignore(1, '\n');
    if (n == 0) break;
    while (n--) {
      string s;
      getline(cin, s);
      ans += s;
      ans += '\n';
    }

    cin >> m;
    cin.ignore(1, '\n');
    while (m--) {
      string s;
      getline(cin, s);
      out += s;
      out += '\n';
    }

    int res; // 0AC 1PE 2WA
    if (ans == out) {
      res = 0;
    } else {
      res = 1;

      string ansdigit, outdigit;
      for (char c : ans)
        if (isdigit(c))
          ansdigit.push_back(c);
      for (char c : out)
        if (isdigit(c))
          outdigit.push_back(c);

      if (ansdigit != outdigit)
        res = 2;
    }

    cout << "Run #" << run << ": ";
    if (res == 0)
      cout << "Accepted\n";
    else if (res == 1)
      cout << "Presentation Error\n";
    else if (res == 2)
      cout << "Wrong Answer\n";
  }

  return 0;
}