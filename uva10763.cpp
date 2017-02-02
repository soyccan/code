// uva10763
// water
#include <bits/stdc++.h>
#define int long long
#define MS(s,v) memset(s,v,sizeof(s))
#define _FOR(i,start,end,step) for (int i=start; i!=end; i+=step)
#define FOR(i,start,end) for (int i=start; i<end; ++i)
using namespace std;
const long long INF = 0x3f3f3f3f3f3f3f3fLL;
int indeg[500005];
int outdeg[500005];
main() {
#ifdef soytw
    freopen("in.txt","r",stdin);
#else
    ios::sync_with_stdio(0);
    cin.tie(0);
#endif
    int n,x,y;
    while (cin>>n && n) {
        MS(outdeg,0);
        MS(indeg,0);
        while (n--) {
            cin>>x>>y;
            outdeg[x]++, indeg[y]++;
        }
        bool ok=1;
        FOR(i,1,500001) if (indeg[i]!=outdeg[i]) ok=0;
        cout<<(ok ? "YES\n" : "NO\n");
    }
#ifdef soytw
    freopen("con","r",stdin);
    system("pause");
#endif
    return 0;
}
