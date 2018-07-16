// undirected, disjoint set
#include <bits/stdc++.h>
#define int long long
#define MS(s,v) memset(s,v,sizeof(s))
#define FOR(i,end) for (int i=0; i<end; ++i)
#define FOR1(i,end) for (int i=1; i<=end; ++i)
using namespace std;
const long long INF = 0x3f3f3f3f3f3f3f3fLL;

const size_t MAXN = 1000010;
bool in[MAXN], out[MAXN];
int ef[MAXN]; // efficiency
int ga[MAXN]; // total gain in a component
int pa[MAXN]; // parent

inline int find(int x) {
    if (x != pa[x])
        pa[x] = find(pa[x]);
    return pa[x];
}

main() {
#ifdef soytw
    freopen("in.txt","r",stdin);
#else
    ios::sync_with_stdio(0);
    cin.tie(0);
#endif

    int n, m, a, b;
    cin >> n >> m;
    FOR(i, n) {
        cin >> ef[i];
        pa[i] = i;
        ga[i] = ef[i];
    }
    while (m--) {
        cin >> a >> b;
        if (find(a) != find(b)) {
            ga[find(b)] += ga[find(a)];
            pa[find(a)] = find(b);
        }
    }

    // FOR(i, n) cout<<ga[find(i)]<<endl;


    int ans = -1;
    FOR(i, n)
        ans = max(ans, ga[find(i)]);
    cout << ans << '\n';


#ifdef soytw
    freopen("con","r",stdin);
    system("pause");
#endif
    return 0;
}
