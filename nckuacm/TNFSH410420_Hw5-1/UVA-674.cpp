// uva 674

#include <bits/stdc++.h>
using namespace std;

int dp[10000];
int coins[] = {1, 5, 10, 25, 50};

int main() {
	int m;
	while (cin >> m) {
		memset(dp, 0, sizeof dp);
		dp[0] = 1;
		for (int c : coins) {
			for (int i=c; i<=m; i++)
				dp[i] += dp[i-c];

			////
			// for (int k=0; k<=m; k++) cout<<dp[k]<<' ';
			// cout <<endl;
		}
		cout << dp[m] << '\n';
	}
	return 0;
}