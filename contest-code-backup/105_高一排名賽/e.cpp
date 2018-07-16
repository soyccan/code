#include <bits/stdc++.h>
using namespace std;

int dp[1000000000][1000000000];

typedef long long ll;
ll qpow(ll a, ll b) {
	ll res = 1;
	while (b > 0) {
		if (b % 2 == 1) res *= a;
		a *= a;
		b /= 2;
	}
	return res;
}

int main()
{
	ll x1, y1, x2, y2;
	cin >> x1 >> y1 >> x2 >> y2;
	int n = log2(x2);
	cout << qpow(3, n) << endl;
	return 0;
}

