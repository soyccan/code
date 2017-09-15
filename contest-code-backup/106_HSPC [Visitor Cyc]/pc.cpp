#include<bits/stdc++.h>
using namespace std;
long long dp[100];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	memset(dp,0,sizeof dp)	;
	dp[1] = dp[0] = 1;
	dp[2] = 5;
	for (int i=3; i<=40; i++)  {
		dp[i] = dp[i-2]*4 + dp[i-1] + dp[i-3]*2;
//		cout<<dp[i]<<' ';
	}
	int t,n;
	cin>>t;
	while(t--)
	{
	    cin>>n;
		cout<<dp[n]<<'\n';
	}
	return 0;
}

