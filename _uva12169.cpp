#include <bits/stdc++.h>
#define int long long
#define MS(s,v) memset(s,v,sizeof(s))
#define FOR(i,st,en) for (int i=st; i<=en; i++)
using namespace std;
int X[10005],_X[10005];
int gcd(int a,int b,int& x,int& y) {
    if (b==0) {
        x=1, y=1;
        return a;
    } else {
        int r=gcd(b,a%b,y,x);
        y-=x*a/b;
        return r;
    }
}
main() {
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    for (int i=1; i<=2*n-1; i+=2) cin>>X[i];
    memcpy(_X,X,sizeof X);
    FOR(a,0,10000) {
        // x3 = ax2 + b (mod 10001)
        // x3 = a(ax1+b) + b (mod 10001)
        // x3 = aax1 + b(a+1) (mod 10001)
        // x3 + 10001k = aax1 + b(a+1)
        // (a+1)b + 10001(-k) = x3 - aax1
        int b,k;
        int g=gcd(a+1,10001,b,k);
        if ((X[3]-a*a*X[1])%g!=0) continue;
        b*=(X[3]-a*a*X[1])/g;

        cout<<"a"<<a<<" B"<<b<<endl;
        bool ok=1;
        FOR(i,2,2*n) {
            X[i]=(a*X[i-1]+b)%10000;
            // cout<<X[i]<<' ';
            if (i&1 && X[i]!=_X[i]) {
                ok=0;
                break;
            }
        }
        // cout<<endl;
        if (ok) break;
    }
    for (int i=2; i<=2*n; i+=2) cout<<X[i]<<' ';
    return 0;
}
