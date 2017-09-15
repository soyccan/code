#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
struct Node {
	int l,r,first,second;
	Node(): first(-1), second(-1) {}
};
int arr[100000005];
Node seg[400000005];
inline void build(int nd, int l, int r) {
	if (l == r) {
		seg[nd].first = seg[nd].second = arr[l];
	} else {
		int m = (l+r)/2;
		build(nd*2, l, m);
		build(nd*2+1, m+1, r);
		if (l + 1 == r)
			seg[nd].first = max(seg[nd*2].first, seg[nd*2+1].first);
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int N,k;
	cin>>N>>k;
	for (int i=0; i<N; i++) cin>>arr[i];
	build(1,0,N);
	return 0;
}
