#include<bits/stdc++.h>
using namespace std;
int n, m, G[105][105], D[105][105];
bool V[105][105];
inline void dfs(int i, int j, int ans) { 

	if ( i-1 >= 0 && G[i-1][j] < G[i][j] )
		dfs(i-1,j,ans+1);
	
	if ( i+1 < n && G[i+1][j] < G[i][j] )
		dfs(i+1,j,ans+1);
	
	if ( j-1 >= 0 && G[i][j-1] < G[i][j] )
		dfs(i,j-1,ans+1);
	
	if ( j+1 < m && G[i][j+1] < G[i][j] )
		dfs(i,j+1,ans+1);
	
	D[i][j] = max(D[i][j],ans);
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;
	while ( T-- ) {
		memset(G,0,sizeof G);
		memset(D,-1,sizeof D);
		memset(V,false,sizeof V);
		string s;
		cin >> s >> n >> m;
		for ( int i=0; i<n; ++i ) {
			for ( int j=0; j<m; ++j )
				cin >> G[i][j];
		}
		for ( int i=0; i<n; ++i )
			for ( int j=0; j<m; ++j ) {
				dfs(i,j,1);
				V[i][j] = true;
			}
		int hi = 0;
		for ( int i=0; i<n; ++i )
			for ( int j=0; j<m; ++j )
				hi = max(hi,D[i][j]);
		cout << s << ": " << hi << '\n';
	}
	return 0;
}
/*
2 Feldberg 10 5
56 14 51 58 88
26 94 24 39 41
24 16 8 51 51
76 72 77 43 10
38 50 59 84 81
5 23 37 71 77
96 10 93 53 82
94 15 96 69 9
74 0 62 38 96
37 54 55 82 38
Spiral 5 5
1 2 3 4 5
16 17 18 19 6
15 24 25 20 7
14 23 22 21 8
13 12 11 10 9

*/
