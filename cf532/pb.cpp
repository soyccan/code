#include <bits/stdc++.h>
#define FOR(i, a, n) for (int i = a; i < n; i++)
using namespace std;

int cnt[112345];
// set<int> S[112345];

int main() {
#ifdef LOCAL
    freopen("in.txt","r",stdin);
#else
    ios::sync_with_stdio(0);
    cin.tie(0);
#endif
    int m,n,x;
    while (cin>>n>>m) {
        memset(cnt, 0, sizeof cnt);
        // FOR(i,0,m+1) S[i].clear();
        int used = 0, stat = 0;
        while (m--) {
            cin>>x;
            if (cnt[x] - used == 0) {
                stat++;
            }
            cnt[x]++;
            // S[cnt[x]].insert(x);

            if (stat == n) {
                cout << 1;
                used++;
                FOR(i,1,n+1) if (cnt[i] - used == 0) stat--;
                // stat -= S[1].size();
                // FOR(i,1,m+1) {
                //     S[i].erase(x);
                //     S[i-1].insert(x);
                // }
            }
            else
                cout << 0;

            // FOR(i,1,n+1) printf("cnt[%d]=%d ", i, cnt[i]);
            // printf("  stat=%d used=%d\n", stat, used);
        }
        cout << '\n';
    }

    return 0;
}
