#include <bits/stdc++.h>
#define int long long
#define MS(a,v) memset(a,v,sizeof a)
#define FOR(i,l,r) for (int i=l; i<=r; ++i)
#define RFOR(i,l,r) for (int i=l; i>=r; --i)
using namespace std;
const int INF = 0x3f3f3f3f3f3f3f3fLL;
int sol[3],ans[3];
inline int calc(int a,int b) {
	return b/a+1;
}
inline update() {
	bool better=0;
	FOR(i,0,2) if (ans[i]==-1 || sol[i]<ans[i]) better=1;
	if (better) memcpy(ans,sol,sizeof ans);
}
inline bool dfs(int d,int maxd,int st,int a,int b) {
    if (d==maxd) {
        if (b%a!=0) return 0;
        sol[d]=b;
        update();
//        FOR(i,0,2) cout<<sol[i]<<' ';
//        cout<<'\n';
        return 1;
    }
    st=max(st,calc(a,b));
    bool ok=0;
    for (int i=st; ; i++) {
        if (a*i>=b*(maxd-d+1)) break;
        int na=a*i-b, nb=b*i;
        int g=__gcd(na,nb);
        sol[d]=i;
        if (na>=0 && dfs(d+1,maxd,i+1,na/g,nb/g))
            ok=1;
    }
    return ok;
}
main() {
//    freopen("in.txt","r",stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t,n,m;
    while (cin>>n) {
		MS(sol,-1); MS(ans,-1);
		dfs(0,2,1,2,n);
        FOR(i,0,2) cout<<ans[i]<<' ';
        cout<<'\n';
    }
    return 0;
}
