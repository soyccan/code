#include <bits/stdc++.h>
#define int long long
#define MS(a,v) memset(a,v,sizeof a)
#define FOR(i,l,r) for (int i=l; i<=r; ++i)
#define RFOR(i,l,r) for (int i=l; i>=r; --i)
using namespace std;
const int INF = 0x3f3f3f3f3f3f3f3fLL;
int sol[3];
bool dfs(int d,int maxd,int st,int a,int b) {
    cout<<' '<<d<<' '<<st<<' '<<a<<' '<<b<<endl;
        FOR(i,0,3) cout<<sol[i];
        cout<<endl;
    if (d==maxd) {
        if (a!=0) return 0;
        sol[d]=b;
        FOR(i,0,2) cout<<sol[i];
        cout<<'\n';
        return 1;
    }
    bool ok=0;
    for (int i=st; ; i++) {
        cout<<'a'<<a<<b<<d<<i<<endl;
        if (a*i>=b*(maxd-d+1)) break;
        int na=a*i-b, nb=b*i;
        int g=__gcd(na,nb);
        sol[d]=i;
        if (na>=0 && dfs(d+1,maxd,i+1,na/g,nb/g)) {
            ok=1;
        }
    }
    return ok;
}
main() {
    freopen("in.txt","r",stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t,n,m;
    while (cin>>n) {
            MS(sol,0);
            if (dfs(0,2,1,2,n)) {
            }
    }
    return 0;
}
