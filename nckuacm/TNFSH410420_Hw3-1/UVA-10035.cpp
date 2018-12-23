#include <bits/stdc++.h>
using namespace std;

int main() {
  int a, b;
  while (cin >> a >> b && (a != 0 || b != 0)) {
    int carry=0, count=0;
    while (a != 0 || b != 0) {
      carry = (carry + a%10 + b%10) / 10;
      if (carry > 0)
        count++;
      a /= 10;
      b /= 10;
    }

    if (count == 0)
      cout << "No carry operation.\n";
    else if (count == 1)
      cout << "1 carry operation.\n";
    else
      cout << count << " carry operations.\n";
  }
  return 0;
}