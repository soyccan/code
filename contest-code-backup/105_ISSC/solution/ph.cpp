#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
// init init init!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
int p[100];
int n;
int dis(int l,int r) {
	if (p[r]-p[l]<0) return p[n]+p[r]-p[l];
	else return p[r]-p[l];
}
bool rect(int a,int b,int c,int d) {
	if (dis(a,b)==dis(c,d) && dis(b,c)==dis(d,a))
		return 1;
	else return 0;
}
main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
//    freopen("in.txt","r",stdin);
    int x;
    while (cin>>n&&n) {
    	p[0]=0;
    	for (int i=1; i<=n; i++) {
    		cin>>x;
    		p[i]=p[i-1]+x;
		}
//    	for (int i=0; i<=n; i++) cout<<i<<' '<<p[i]<<endl;
		int cnt=0;
    	for (int i=1; i<=n; i++)
   	    	for (int j=i+1; j<=n; j++)
		    	for (int k=j+1; k<=n; k++)
			    	for (int l=k+1; l<=n; l++)
			    		if (rect(i,j,k,l)) cnt++;
		cout<<cnt<<endl;
	}
	return 0;
}


