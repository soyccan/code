#include <bits/stdc++.h>
using namespace std;
int N,M;
int arr[1000005];
int happy(int l, int r) {
	for (int i=l; i<r; i++)
		if (arr[i]+1!=arr[i+1])
			return -1;
	return r-l+1;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int a,b,c,q;
	cin>>N;
	for (int i=1; i<=N; i++) cin>>arr[i];
	cin>>q;
	while (q--) {
		cin>>c>>a>>b;
		if (c==1)
			arr[a]=b;
		else {
			int len=-1;
			for (int i=a; i<=b; i++)
				for (int j=i; j<=b; j++)
					len=max(len,happy(i,j));
			cout<<len<<'\n';
		}
	}
	return 0;
}
