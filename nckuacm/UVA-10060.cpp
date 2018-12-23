#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	double h, r, t, x[1000], y[1000];
	double pi = acos(-1);
	while (cin >> n && n != 0) {
		double vol = 0;
		while (n--) {
			cin >> h >> x[0] >> y[0];
			int cnt = 1;
			while (1) {
				cin >> x[cnt] >> y[cnt];
				if (x[cnt] == x[0] && y[cnt] == y[0]) break;
				cnt++;
			}
			double area = 0;
			for (int i=0; i<cnt; i++)
				area += x[i]*y[i+1] - y[i]*x[i+1];
			vol += abs(area/2)*h;
		}
		cin >> r >> t;
		cout << int(vol/(pi*r*r*t)) << '\n';
	}
	return 0;
}