#include <bits/stdc++.h>
using namespace std;
//#define int long long
#define endl '\n'
// init init init!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    //freopen("in.txt","r",stdin);
    double vt,v0,k;
    while (cin>>vt>>v0&&vt&&v0) {
    	double ans=-1e9;
    	k=0;
    	bool flag=0;
	    for (double i=1; i<vt/v0; i++) 
	    	if (i*v0<vt&& 0.3*sqrt(vt/i-v0)*i >= ans) {
	    		if(0.3*sqrt(vt/i-v0)*i == ans)flag=1;
	    		else flag=0;
				ans = 0.3*sqrt(vt/i-v0)*i;
	    		cout<<ans<<endl;
	    		k=i;
	    		
			}
		if(flag==1) cout<<0<<endl;
	    else cout<<k<<endl;
	}
	return 0;
}


