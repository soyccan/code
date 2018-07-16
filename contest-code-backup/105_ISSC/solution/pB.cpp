#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
// init init init!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
__int128 f[105],g[105],pw[105];
string tos(__int128 x) {
	string s;
	while (x) {
		s.push_back('0'+x%10);
		x/=10;
	}
	reverse(s.begin(),s.end());
	return s;
}
main() {
    pw[0]=1;
    for(int i=1;i<=100;++i) pw[i]=pw[i-1]*2;
    int n,k;
    while(cin>>n>>k)
    {
    	if(n==0) break;
    	for(int i=0;i<=100;++i) f[i]=0;
	    for(int i=0;i<k;++i) g[i]=pw[i];
	    for(int i=k;i<=n;++i)
	    {
	    	for(int j=i;j<=n;++j)
			{
				if(i!=k) f[j]+=g[i-k-1]*pw[j-i];
				else f[j]+=pw[j-i];
			}
			g[i]=pw[i]-f[i];
		}	
		cout<<tos(f[n])<<endl;  	
	}
	return 0;
}
