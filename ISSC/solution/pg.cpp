#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
// init init init!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
bool G[100][100];
bool ok(int a,int b,int c,int d) {
	if ((G[a][b]&&G[b][d]&&G[d][c]&&G[c][a]) ||
	    (G[a][b]&&G[b][c]&&G[c][d]&&G[d][a]) ||
	    (G[a][d]&&G[d][c]&&G[c][b]&&G[b][a]) ||
	    (G[a][d]&&G[d][b]&&G[b][c]&&G[c][a]) ||
	    (G[a][c]&&G[c][b]&&G[b][d]&&G[d][a]) ||
	    (G[a][c]&&G[c][b]&&G[b][d]&&G[d][a])) {
//			cout<<a<<b<<c<<d<<endl;
			return true;
	}
	else return false;
}
main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
//    freopen("in.txt","r",stdin);
    int n;
	while (cin>>n&&n) {
	    for (int i=1; i<=n; i++)
		    for (int j=1; j<=n; j++)
		    	cin>>G[i][j];
		bool f=0;
	    for (int i=1; i<=n; i++)
		    for (int j=i+1; j<=n; j++)
	    		for (int k=j+1; k<=n; k++)
	    			for (int l=k+1; l<=n; l++)
	    				if (ok(i,j,k,l)) {
	    					f=1;
	    					break;
						}
		if (f) cout<<"yes\n";
		else cout<<"no\n";
	}
	return 0;
}


