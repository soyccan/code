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
				return true;
			}
		}
	}
	return false;
}

int main() {
	int n,m,s,v;
	while(cin>>n>>m>>s>>v) {
		for (int i=0; i<n; i++) {
			cin>>a[i].x>>a[i].y;
			G[i].clear();
		}
		for (int i=0; i<m; i++)
			cin>>b[i].x>>b[i].y;
		for (int i=0; i<n; i++)
			for (int j=0; j<m; j++)
				if (dis(a[i], b[j]) < v*s)
					G[i].push_back(j);
	
		int ans = 0;
		memset(match, -1, sizeof match);
		for (int i=0; i<n; i++) {
			memset(used, 0, sizeof used);
			if (dfs(i)) ans++;
		}
		cout << n-ans << endl;
	}
	return 0;
}
