#include <bits/stdc++.h>
using namespace std;

int n;
string s;

bool match(int p) {
  for (int i=p; i<s.size(); i++)
    if (s[i] != s[i%p])
      return false;
  return true;
}

int main() {
  cin>>n;
  while (n--) {
    cin>>s;
    for (int i=1; i<=s.size(); i++) { // period
      if (s.size() % i == 0 && match(i)) {
        cout << i << "\n";
        break;
      }
    }
    if (n > 0) cout << '\n';
  }

  return 0;
}
