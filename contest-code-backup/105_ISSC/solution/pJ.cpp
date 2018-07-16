#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
// init init init!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
#define INF 100000000000000
int a[35],dp[35],next[35];
main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    //freopen("in.txt","r",stdin);
    int n;
    while(cin>>n,n!=0)
    {
    	if(n==0) break;
    	for(int i=1;i<=n;++i) dp[i]=INF;
    	for(int i=1;i<=n;++i) cin>>a[i];
    	for(int i=1;i<=n;++i)
    	{
    		for(int j=0;j<i;++j)
    		{
    			int x=dp[j] + (200-(a[i]-a[j]))*(200-(a[i]-a[j]));
    			if(dp[i]> x) next[i]=j,dp[i]=x;
			}
		}
//		cout<<"dp:";
//		for(int i=0;i<=n;++i) cout<<dp[i]<<' ';cout<<endl;
		stack<int> ans;
		for(int i=n;i!=0;i=next[i]) ans.push(i);
		ans.push(0);
		while(ans.size())
		{
			if(ans.size()==1)  cout<<ans.top(),ans.pop();
			else  cout<<ans.top()<<' ',ans.pop();
		}
		cout<<endl;
	}
	return 0;
}
/*
4
190 260 385 540
5 
130 180 230 330 450
0
*/

