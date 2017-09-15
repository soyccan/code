#include "Gift.h"
using namespace std;

int ask[1000005];

int bs(int l, int r) {
  if (l == r) return l;
  int m = (l+r)/2;

  for (int i=l; i<=m; i++)
    ask[i-l] = i;
  if (AskNana(m-l+1, ask))
    return bs(l, m);
  else
    return bs(m+1, r);
  
  return -1;
}

int AnnGuess(int N) {
  return bs(0, N-1);
}
