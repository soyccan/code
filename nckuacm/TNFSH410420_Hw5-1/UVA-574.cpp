// uva574

#include <bits/stdc++.h>
using namespace std;

bool used[20];
int arr[20], com[20];
int t, n;

void backtrack(int begin, int end, int sum) {
  if (sum == t) {
    for (int i=0; i<end-1; i++)
      cout << com[i] << '+';
    cout << com[end-1] << '\n';
  } else {
    for (int i=begin; i<n; i++) {
      if (!used[i]) {
        used[i] = true;
        com[end] = arr[i];
        backtrack(i+1, end+1, sum+arr[i]);
        used[i] = false;
      }
    }
  }
}

int main() {
  while (cin >> t >> n && n != 0) {
    for (int i=0; i<n; i++)
      cin >> arr[i];
    sort(arr, arr+n, greater<int>());
    memset(used, false, sizeof used);
    backtrack(0, 0, 0);
  }
  return 0;
}
