#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
int arr[10000005];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,x,a,b;
	cin>>n>>x>>a>>b;
	bool flag = (a==b);
	for (int i=1; i<=n; i++) {
		cin>>arr[i];
		if (a * x == b * arr[i])
			flag=true;
	}
	if (flag) cout<<"Yes\n";
	else cout<<"No\n";
	return 0;
}