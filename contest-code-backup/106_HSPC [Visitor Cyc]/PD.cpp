#include<bits/stdc++.h>
#define maxn 105
using namespace std;
long long dp[maxn] , sum[maxn];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	for(int i=1;i<maxn;i++)    dp[i] = 1;
	memset(sum,0,sizeof sum);
	sum[1] = 1;
	sum[2] = 2;
	for(int i=3;i<maxn;i++)
	{
		dp[i] += sum[i-2];
		sum[i] = dp[i] + sum[i-1];
	}
//	for(int i=1;i<10;i++)
//	    cout << dp[i] << " ";
//	cout << endl;
	int t;
	cin >> t;
	int s,n;
	int kase = 1;
	while(t--)
	{
		cin >> s >> n;
		cout << "Case #" << kase++ << ": ";
		cout << sum[n] - sum[s-1] << endl;
	}
	return 0;
}

