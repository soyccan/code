#include <bits/stdc++.h>
using namespace std;
int N,M;
int arr[100005],cost[100005];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int a,b;
	cin>>N>>a>>b;
	for (int i=0; i<N; i++) cin>>arr[i]>>cost[i];
	if (a==b) cout<<"0\n";
	else {
		int ans=1e8;
		for (int i=0; i<N; i++) {
			if (arr[i]*a%b==0 && has[arr[i]*a/b])
				ans=min(ans,cost[i]+cost[j]);
		}
		if (ans == 1e8)cout<<"-1\n";
		else cout<<ans<<'\n';
	}
	return 0;
}