#include <iostream>
#include <algorithm>
using namespace std;

template<typename SequenceContainer>
bool next_perm(SequenceContainer& perm) {
  /* seek the next permutation, return false when reaching the last */
  if (perm.size() <= 1)
    return false;

  int left = perm.size() - 2;
  while (perm[left] >= perm[left+1]) {
    left--;
    if (left < 0)
      return false;
  }

  int right = perm.size() - 1;
  while (perm[left] >= perm[right]) {
    right--;
  }

  swap(perm[left], perm[right]);
  reverse(perm.begin()+left+1, perm.end());
  return true;
}

int main() {
  string letters;
  cin >> letters;
  sort(letters.begin(), letters.end());

  for (int i=1; ; i++) {
    cout << i << ' ' << letters << endl;
    if (!next_perm(letters))
      break;
  }

  return 0;
}