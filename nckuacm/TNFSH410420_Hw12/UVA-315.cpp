#include <bits/stdc++.h>
using namespace std;
 
int n;
vector<int> G[1000];
int dep[1000], low[1000];
int ans;
 
void dfs(int p, int pa) {
	int child = 0;
	bool artic = false;
	for (int q : G[p]) {
		if (!dep[q]) {
			low[q] = dep[q] = dep[p]+1;
			child++;
			dfs(q, p);
			low[p] = min(low[p], low[q]);
			if (low[q] >= dep[p])
				artic = true;
		} else if (q != pa) {
			low[p] = min(low[p], dep[q]);
		}
	}
 
	if ((pa != -1 || child > 1) && artic) // pa==1: root
		ans++;
}
 
int main() {
	while (cin>>n && n!=0) {
		for (int i=0; i<=n; i++)
			G[i].clear();
 
		string s;
		scanf("\n");
		while (getline(cin, s)) {
			stringstream ss(s);
			int p, q;
			ss >> p;
			if (p == 0) break;
			while (ss >> q) {
				G[p].push_back(q);
				G[q].push_back(p);
			}
		}

		memset(dep, 0, sizeof dep);
		memset(low, 0, sizeof low);
		low[1] = dep[1] = 1;
		ans = 0;
		dfs(1, -1);
		cout << ans << '\n';
	}
	return 0;
}
