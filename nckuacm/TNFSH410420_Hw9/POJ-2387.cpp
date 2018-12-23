#include <iostream>
#include <vector>
using namespace std;

struct Edge {
	int a,b,dis;
};

vector<Edge> G;
int dis[3000];

int main() {
	int t, n;
	cin>>t>>n;
	while (t--) {
		int a, b, dis;
		cin>>a>>b>>dis;
		G.push_back(Edge{a,b,dis});
		G.push_back(Edge{b,a,dis});
	}

	dis[1] = 0;
	for (int i=2; i<=n; i++)
		dis[i] = 1000000;

	for (int i=1; i<=n-1; i++) {
		for (int j=0; j<G.size(); j++) {
			Edge e = G[j];
			dis[e.b] = min(dis[e.b], dis[e.a]+e.dis);
		}
	}

	cout << dis[n] << '\n';
	
	return 0;
}