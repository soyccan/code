#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
// init init init!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
//    freopen("in.txt","r",stdin);
    string a,b;
    int tc=1;
    while (cin>>a&&a!="0") {
    	cin>>b;
    	int x=0,y=0;
    	for (int i=0; i<a.size(); i++)
    		x+=(a[i]-'0')*(1<<(a.size()-i-1));
    	for (int i=0; i<b.size(); i++)
    		y+=(b[i]-'0')*(1<<(b.size()-i-1));
//    		cout<<x<<' '<<y<<endl;
    	if (__gcd(x,y)==1) cout<<"Pair #"<<tc<<": Love is not all you need!\n";
    	else cout<<"Pair #"<<tc<<": All you need is love!\n";
    	tc++;
	}
	return 0;
}


