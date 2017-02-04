#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
int arr[100000005];
int tmp[100000005];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int N,k;
	cin>>N>>k;
	for (int i=0; i<N; i++) cin>>arr[i];
	int ans = -1;
	for (int i=0; i<=N-k; i++) {
		vector<int> v;
		for (int j=i; j<i+k; j++) {
			v.push_back(arr[j]);
		}
		sort(v.begin(), v.end());
		ans = max(ans, v[k-2]);
	}
	cout<<ans<<endl;
	return 0;
}
