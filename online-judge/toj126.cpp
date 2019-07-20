#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int pow2(int exponent) {
  return 1 << exponent;
}

int log2(int arg) {
  if (arg == 1)
    return 0;
  else
    return log2(arg>>1) + 1;
}

vector<int> possible_sum(vector<int> data) {
  vector<int> result;
  int bt[pow2(data.size()+1)]; // binary tree
  bt[1] = 0; // root

  for (int i=2; i<pow2(data.size()+1); i+=2) {
    bt[i] = bt[i/2];
    bt[i+1] = bt[i/2] + data[log2(i)-1];
    if (i >= pow2(data.size())) {
      result.push_back(bt[i]);
      result.push_back(bt[i+1]);
    }
  }
  sort(result.begin(), result.end());
  result.erase(unique(result.begin(), result.end()), result.end());
  return result;
}

int main() {
  int n, q;
  scanf("%d %d", &n, &q);

  vector<int> exercise(n);
  for (int i=0; i<n; i++) {
    scanf("%d", &exercise[i]);
  }

  vector<int> p = possible_sum(exercise);
  for (int i=0; i<q; i++) {
    int score;
    scanf("%d", &score);
    for (int j : p) {
      if (j >= score) {
        printf("%d\n", j);
        break;
      }
    }
  }

  return 0;
}