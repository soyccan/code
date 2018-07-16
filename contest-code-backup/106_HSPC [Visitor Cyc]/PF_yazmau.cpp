#include<bits/stdc++.h>
#define maxn 105
#define pii pair<int,int>
using namespace std;
int arr[maxn][maxn];
struct yee{
	int cost,y,x;
}pos[maxn*maxn];
bool operator <(yee a,yee b)
{
	return a.cost < b.cost;
}
int dp[maxn][maxn];
int y[] = {0,-1,0,1};
int x[] = {-1,0,1,0};
int n,m;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;
	while ( T-- )
	{
		string s;
		cin >> s >> n >> m;
		int cur = 0;
		for ( int i=0; i<n; ++i )
			for ( int j=0; j<m; ++j )
			{
				cin >> arr[i][j];
				pos[cur++] = yee{arr[i][j],i,j};
			}
		sort(pos,pos+cur);
		memset(dp,-1,sizeof dp);
		int nx,ny;
		int ans = 0;
		for(int i=0;i<cur;i++)
		{
			int nowy = pos[i].y;
			int nowx = pos[i].x;
			dp[nowy][nowx] = 1;
			for(int w=0;w<4;w++)
			{
			    ny = nowy + y[w] , nx = nowx + x[w];
			    if(ny < 0 || ny >= n || nx < 0 || nx >= n)    continue;
			    if(dp[ny][nx] != -1 && arr[nowy][nowx] > arr[ny][nx] )
			        dp[nowy][nowx] = max(dp[nowy][nowx],dp[ny][nx]+1);
			}
			ans = max(ans,dp[nowy][nowx]);
		}
		cout << s << ": " << ans << endl;
	}
	return 0;
}

