#include <bits/stdc++.h>
#define int long long
const int MAXN = 1e18+10;
using namespace std;
int a[10000]; // factorial
vector<int> num;
main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	a[1]=1;
	int n=1;
	for (int i=2; ; i++) {
		a[i]=a[i-1]*i;
		if (a[i]>MAXN) {
			n=i;
			break;
		}
	}
	// cout<<"n:"<<n<<endl;
	// for (int i=1; i<=n; i++)
	// 	cout<<a[i]<<endl;
	num.push_back(2);
	for (int i=1; i<=n; i++)
		for (int j=i+2; j<=n; j++)
			num.push_back(a[j]/a[i]);
	sort(num.begin(), num.end());
	num.erase(unique(num.begin(), num.end()), num.end());
	for (int i:num) cout<<i<<'\n';
	int t,l,r;
	cin>>t;
	while (t--) {
		cin>>l>>r;
		cout<<upper_bound(num.begin(), num.end(),r)-lower_bound(num.begin(), num.end(),r)<<'\n';
	}
	return 0;
}
