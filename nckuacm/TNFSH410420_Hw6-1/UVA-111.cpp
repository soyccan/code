// uva111

#include <bits/stdc++.h>
using namespace std;

int a[30], b[30], lcs[30][30];

int main() {
	int n, x;
	while (cin >> n) {
		for (int i=1; i<=n; i++) {
			cin >> x;
			a[x] = i;
		}

		while (cin >> x) {
			b[x] = 1;
			for (int i=2; i<=n; i++) {
				cin >> x;
				b[x] = i;
			}

			memset(lcs, 0, sizeof lcs);
			for (int i=1; i<=n; i++)
				for (int j=1; j<=n; j++)
					if (a[i] == b[j])
						lcs[i][j] = lcs[i-1][j-1] + 1;
					else
						lcs[i][j] = max(lcs[i][j-1], lcs[i-1][j]);
						
			///
			// for (int i=1; i<=n; i++) {
			// 	for (int j=1; j<=n; j++)
			// 		cout << lcs[i][j] << ' ';
			// 	cout << endl;
			// }
						
			cout << lcs[n][n] << '\n';
		}
	}		
	return 0;
}