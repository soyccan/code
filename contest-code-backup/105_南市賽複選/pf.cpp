#include <bits/stdc++.h>
using namespace std;
struct S {
	int a,b;
	bool operator<(S s) const {
		return a<s.a;
	}
};
int N,M;
S arr[100005];
bool used[100005]={0};
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int a,b;
	cin>>N>>a>>b;
	for (int i=0; i<N; i++) {
		cin>>arr[i].a>>arr[i].b;
		used[arr[i].a]=1;
	}
	sort(arr,arr+N);
	if (a==b) cout<<"0\n";
	else {
		int ans=1e8;
		for (int i=0; i<N; i++) {
			int x = arr[i].a*a/b;
			if (arr[i].a*a%b != 0 || !used[x]) continue;
			auto y = lower_bound(arr,arr+N,S{x,0});
			// cout<<arr[i].a<<' '<<x<<' '<<*y<<endl;
			ans=min(ans,arr[i].b + y->b);
		}
		if (ans == 1e8)cout<<"-1\n";
		else cout<<ans<<'\n';
	}
	return 0;
}