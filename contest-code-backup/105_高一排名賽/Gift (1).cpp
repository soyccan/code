#include "Gift.h"
using namespace std;

int ask[1000005];

int bs(int l, int r) {
	if (r-l == 1) {
		ask[0] = l;
		int lres = AskNana(1, ask), rres;
		if (lres) return l;
		else {
			ask[0] = r;
			rres = AskNana(1, ask);
		}

		if (rres) return r;
		else return -1;
	}

	int m = (l+r)/2;
	int lpos=-1, rpos=-1;
	for (int i=l; i<=m; i++)
		ask[i-l] = i;
	if (AskNana(m-l+1, ask))
		lpos = bs(l, m);

	if (lpos != -1) return lpos;
	else {
		for (int i=m+1; i<=r; i++)
			ask[i-m-1] = i;
		if (AskNana(r-m, ask))
			rpos = bs(m+1, r);
	}
	if (rpos != -1) return rpos;
	else return -1;
}

int AnnGuess(int N)
{
	return bs(0, N-1);
}
