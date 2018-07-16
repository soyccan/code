// fibonacci
#include <bits/stdc++.h>
#define int unsigned long long
#define MS(s,v) memset(s,v,sizeof(s))
#define FOR(i,st,en) for (int i=st; i<=en; i++)
using namespace std;
const int MAXN = 1e8;
int f[MAXN+5];
int qpow(__int128 x,__int128 y,__int128 m) {
    __int128 r=1;
    x%=m;
    while (y) {
        if (y&1) r=r*x%m;
        x=x*x%m;
        y/=2;
    }
    return r%m;
}
main() {
    // freopen("in.txt","r",stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t,n,en,a,b;
    cin>>t;
    while (t--) {
        cin>>a>>b>>n;
        f[0]=0, f[1]=1;
        FOR(i,2,n*n) {
            f[i]=(f[i-1]+f[i-2])%n;
            if (f[i]==1 && f[i-1]==0) { en=i-1; break; }
        }
        if (n==1) cout<<"0\n";
        else cout<<f[qpow(a,b,en)]<<'\n';
    }
    return 0;
}
