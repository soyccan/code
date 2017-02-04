#include <iostream>
#define int long long
#define FOR(i,l,r) for (int i=l; i<r; i++)
using namespace std;
void solve(int n) {
	FOR(i,0,n+1)
		FOR(j,i,n+1)
			FOR(k,j,n+1)
				FOR(l,k,n+1)
					if (i*i + j*j + k*k + l*l == n) {
						cout<<i<<' '<<j<<' '<<k<<' '<<l<<'\n';
						return;
					}
}
main() {
//    ios::sync_with_stdio(false);
//    cin.tie(0);
	int n;
	cin>>n;
	solve(n);
	return 0;
}

