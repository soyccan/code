#include <bits/stdc++.h>
using namespace std;

vector<int> pa;

int find(int x) {
	if (x != pa[x])
		pa[x] = find(pa[x]);
	return pa[x];
}

void U(int x, int y) {
	pa[find(x)] = find(y);
}

int main() {
	int c=0;
	int t;
	cin >> t;
	while (t--) {
		c++;
		if (c>1) cout<<'\n';
		int n;
		cin >> n;
		// cout << "n:" << n <<endl;
		pa.resize(n+2);
		for (int i=1; i<=n; i++)
			pa[i] = i;

		int yes=0, no=0;
		string s;
		getchar(); // new line
		while (getline(cin, s)) {
			// cout << "s:" << s << endl;
			if (s == "") break;

			stringstream ss(s);
			char c;
			int a, b;
			ss >> c >> a >> b;

			if (c == 'c')
				U(a, b);
			else if (c == 'q')
				if (find(a) == find(b)) yes++;
				else no++;
		}
		printf("%d,%d\n", yes, no);
	}
	return 0;
}
