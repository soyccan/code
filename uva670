// uva670
// bipartite matching

#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>
using namespace std;

struct P {
	double x, y;
};

P a[1000], b[1000];
vector<int> G[1000];
int match[1000];
int rmatch[1000];
bool used[1000];

double dis(P a, P b) {
	return sqrt(pow(a.x-b.x, 2) + pow(a.y-b.y, 2));
}

int dfs(int x) {
	for (int y : G[x]) {
		if (!used[y]) {
			used[y] = true;
			if (match[y] == -1 || dfs(match[y])) {
				match[y] = x;
				rmatch[x] = y;
				return true;
			}
		}
	}
	return false;
}

int main() {
	int n,m,t;
	cin>>t;
	while (t--) {
		cin>>n>>m;
		for (int i=0; i<n; i++) {
			cin>>a[i].x>>a[i].y;
			G[i].clear();
		}
		for (int i=0; i<m; i++)
			cin>>b[i].x>>b[i].y;
		for (int i=0; i<n-1; i++)
			for (int j=0; j<m; j++)
				if (dis(a[i], b[j]) + dis(b[j], a[i+1]) <= dis(a[i], a[i+1])*2)
					G[i].push_back(j);

		int ans = 0;
		memset(match, -1, sizeof match);
		memset(rmatch, -1, sizeof rmatch);
		for (int i=0; i<n; i++) {
			memset(used, 0, sizeof used);
			if (dfs(i)) ans++;
		}
		cout << n+ans << endl;
		for (int i=0; i<n; i++) {
			cout << a[i].x << ' ' << a[i].y;
			if (i != n-1) cout<<' ';
			if (rmatch[i] != -1) {
			   cout << b[rmatch[i]].x<<' '<<b[rmatch[i]].y;
			   if (i != n-1) cout<<' ';
			}
		}
		cout << endl;
		if (t != 0) cout << endl;
	}
	return 0;
}
