// cf743
// DP
#include <bits/stdc++.h>
#define int long long
#define MS(a,v) memset(a,v,sizeof a)
#define FOR(i,l,r) for (int i=l; i<=r; ++i)
#define RFOR(i,l,r) for (int i=l; i>=r; --i)
using namespace std;
const int INF = 0x3f3f3f3f3f3f3f3fLL;
int dp[200005];
int sum[200005];
int arr[200005];
vector<int> G[200005];
int ans;
inline int DP(int x,int p) {
	if (dp[x]!=-INF) return dp[x];
	dp[x]=sum[x];
	vector<int> v;
	for (int y:G[x]) {
		if (y!=p) {
			int k=DP(y,x);
			dp[x]=max(dp[x],k);
			v.push_back(k);
		}
	}
	sort(v.begin(),v.end(),greater<int>());
	if (v.size()>=2) ans=max(ans,v[0]+v[1]);
}
inline int dfs(int x,int p) {
	sum[x]=arr[x];
	for (int y:G[x]) if (y!=p) sum[x]+=dfs(y,x);
	return sum[x];
}
main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t,n,m,a,b;
	while (cin>>n) {
		FOR(i,1,n) G[i].clear();
		FOR(i,1,n) cin>>arr[i];
		FOR(i,1,n-1) {
			cin>>a>>b;
			G[a].push_back(b);
			G[b].push_back(a);
		}
		FOR(i,1,n) dp[i]=-INF;
		ans=-INF;
		dfs(1,-1);
		DP(1,-1);
		if (ans==-INF) cout<<"Impossible\n";
		else cout<<ans<<'\n';
	}
	return 0;
}
