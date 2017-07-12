#include<bits/stdc++.h>
using namespace std;
long long dp[100], ans;
vector<int> sol;
void dfs(int sum,int t) {
	if (sum == t) {
		ans++; 
		return ;
	}
	if (sum > t) return;
	int i = 1;
	if (sol.size()) i=sol.back();
	for (; sum+i<=t; i++) {
		sol.push_back(i);
		dfs(sum+i, t);
		sol.pop_back();
	}
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	memset(dp,-1,sizeof dp);
	int n;
	while (cin>>n) {
		if (dp[n]==-1) {
			ans=0;
			sol.clear();
			dfs(0,n);
			cout<<(dp[n]=ans)<<'\n';
		} else {
			cout<<dp[n]<<'\n';
		}
	}
	return 0;
}

