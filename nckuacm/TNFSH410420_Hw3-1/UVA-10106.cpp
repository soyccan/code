#include <bits/stdc++.h>
using namespace std;

int main() {
	string s, t;
	while (cin >> s >> t) {
		deque<int> a, b;
		for (char c : s)
			a.push_front(c - '0');
		for (char c : t)
			b.push_front(c - '0');

		vector<int> c(a.size()+b.size());
		for (int i=0; i<a.size(); i++)
			for (int j=0; j<b.size(); j++)
				c[i+j] += a[i] * b[j];

		for (int i=1; i<c.size(); i++) {
			c[i] += c[i-1] / 10;
			c[i-1] %= 10;
		}

		int i = c.size() - 1;
		while (c[i] == 0 && i > 0)
			i--;
		while (i >= 0)
			cout << c[i--];
		cout << '\n';
	}

	return 0;
}
