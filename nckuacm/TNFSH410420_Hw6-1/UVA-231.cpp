// uva231

#include <bits/stdc++.h>
using namespace std;

int main() {
	int x, c=1;
	while (1) {
		vector<int> seq {-1};
		cin >> x;
		if (x < 0) break;
		do {
			if (x <= seq.back())
				seq.push_back(x);
			else
				*upper_bound(seq.begin(), seq.end(), x, greater<int>()) = x;
		} while (cin >> x && x >= 0);
		
		if (c > 1) cout << '\n';
		printf("Test #%d:\n", c++);
		printf("  maximum possible interceptions: %d\n", seq.size());
	}
	return 0;
}