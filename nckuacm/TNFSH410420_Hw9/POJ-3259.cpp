#include <iostream>
#include <vector>
using namespace std;

struct Edge {
	int a,b,dis;
};

vector<Edge> G;
int dis[3000];

int main() {
	int t,n,m,w;
	cin>>t;
	while (t--) {
		cin>>n>>m>>w;
		G.clear();
		while (m--) {
			int a, b, dis;
			cin>>a>>b>>dis;
			G.push_back(Edge{a,b,dis});
			G.push_back(Edge{b,a,dis});
		}
		while (w--) {
			int a, b, dis;
			cin>>a>>b>>dis;
			G.push_back(Edge{a,b,-dis});
		}

		dis[1] = 0;
		for (int i=2; i<=n; i++)
			dis[i] = 100000;

		int i=0;
		for (i=0; i<n+10; i++) {
			bool relax = false;
			for (int j=0; j<G.size(); j++) {
				Edge e = G[j];
				if (dis[e.a]+e.dis < dis[e.b]) {
					dis[e.b] = dis[e.a]+e.dis;
					relax = true;
				}
			}
			if (!relax) break;
		}

		if (i >= n-1)
			cout << "YES\n";
		else
			cout << "NO\n";
	}

	return 0;
}