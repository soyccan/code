// poj 3253

#include <iostream>
#include <queue>
using namespace std;
typedef long long ll;

int main() {
	priority_queue<ll, vector<ll>, greater<ll>> pq;
	int n;
	cin >> n;
	while (n--) {
		ll l;
		cin >> l;
		pq.push(l);
	}
	ll sum = 0;
	while (pq.size() >= 2) {
		ll x = pq.top();
		pq.pop();
		x += pq.top();
		pq.pop();

		sum += x;
		pq.push(x);
	}
	cout << sum << '\n';
	return 0;
}