// uva10298
// KMP
#include <bits/stdc++.h>
#define int long long
#define MS(s,v) memset(s,v,sizeof(s))
#define _FOR(i,start,end,step) for (int i=start; i!=end; i+=step)
#define FOR(i,start,end) for (int i=start; i<end; ++i)
using namespace std;
const long long INF = 0x3f3f3f3f3f3f3f3fLL;
int fail[1000005];
main() {
#ifdef soytw
    freopen("in.txt","r",stdin);
#else
    ios::sync_with_stdio(0);
    cin.tie(0);
#endif
    string s;
    while (cin>>s && s!=".") {
        int n = s.size();
        MS(fail,-1);
        int p=-1;
        FOR(i,1,n) {
            while (p!=-1 && s[p+1]!=s[i]) p=fail[p];
            if (s[p+1]==s[i]) fail[i]=++p;
        }
        int k=fail[n-1];
        if (n%(n-1-k) == 0) cout<<n/(n-1-k)<<'\n';
        else cout<<1<<'\n';
    }
#ifdef soytw
    freopen("con","r",stdin);
    system("pause");
#endif
    return 0;
}
