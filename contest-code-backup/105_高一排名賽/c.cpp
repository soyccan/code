#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll qpow(ll a, ll b, ll mod) {
	ll res = 1;
	while (b > 0) {
		if (b % 2 == 1) res = res*(a%mod)%mod;
		a = a*(a%mod)%mod;
		b /= 2;
	}
	return res%mod;
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);

	ll mod = 100000007;
	ll ans = 1;
	ll m, n, x;
	cin >> m >> n;

	for (int i=0; i<m; i++) {
		cin >> x;
		ans = ans*qpow(x, n, mod)%mod;
	}
	for (int i=0; i<n; i++) {
		cin >> x;
		ans = ans*qpow(x, m, mod)%mod;
	}
	cout << ans%mod << endl;

	return 0;
}

