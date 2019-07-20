#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
  int count;
  cin >> count;

  for (; count>0; count--) {
    int len;
    cin >> len;

    vector<int> seq(len);
    for (int i=0; i<len; i++) {
      cin >> seq[i];
    }

    if (len % 2 == 0) {
      nth_element(seq.begin(), seq.begin() + len/2 - 1, seq.end());
      nth_element(seq.begin(), seq.begin() + len/2, seq.end());
      cout << (seq[len/2-1]+seq[len/2])/2 << endl;
    } else {
      nth_element(seq.begin(), seq.begin() + len/2, seq.end());
      cout << seq[len/2] << endl;
    }
  }

  return 0;
}