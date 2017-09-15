#include "Gift.h"
using namespace std;

int bs(int l, int r) {
	if (l == r) {
		int ask[] = {l};
		return AskNana(1, ask);
	}
	else {
		int m = (l+r)/2;
		return bs(l, m) + bs(m+1, r);
	}
}

int AnnGuess(int N)
{
	return bs(0, N-1);
}
