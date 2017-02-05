// uva11297
// 2d segment tree
#include <bits/stdc++.h>
// #define int long long
#define MS(s,v) memset(s,v,sizeof(s))
#define _FOR(i,start,end,step) for (int i=start; i!=end; i+=step)
#define FOR(i,start,end) for (int i=start; i<end; ++i)
using namespace std;
// const long long INF = 0x3f3f3f3f3f3f3f3fLL;
const int INF = 1e9;

struct SegTree {
    int Max[2005][2005], Min[2005][2005], n;
    int x, y, v; // update args
    int qt, qb, ql, qr, mx, mn; // query args and result
    void query() { mx=-INF; mn=INF; query2d(1,1,n); }
    void update() { update2d(1,1,n); }
    void query1d(int i, int j, int l, int r) {
        if (ql <= l && r <= qr) {
            mx = max(mx, Max[i][j]);
            mn = min(mn, Min[i][j]);
            return;
        }
        int m = (l + r) / 2;
        if (ql <= m) query1d(i, j*2, l, m);
        if (qr > m) query1d(i, j*2+1, m+1, r);
    }
    void query2d(int i, int t, int b) {
        if (qt <= t && b <= qb) {
            query1d(i, 1, 1, n);
            return;
        }
        int m = (t + b) / 2;
        if (qt <= m) query2d(i*2, t, m);
        if (qb > m) query2d(i*2+1, m+1, b);
    }
    void update1d(int i, int j, int l, int r) {
        if (y == l && y == r) {
            Max[i][j] = Min[i][j] = v;
            return;
        }
        int m = (l + r) / 2;
        if (y <= m) update1d(i, j*2, l, m);
        else update1d(i, j*2+1, m+1, r);
        Max[i][j] = max(Max[i][j*2], Max[i][j*2+1]);
        Min[i][j] = min(Min[i][j*2], Min[i][j*2+1]);
    }
    void update2d(int i, int t, int b) {
        if (t == x && x == b) {
            update1d(i, 1, 1, n);
            return;
        }
        int m = (t + b) / 2;
        if (x <= m) update2d(i*2, t, m);
        else update2d(i*2+1, m+1, b);
        merge1d(i, 1, 1, n);
    }
    void merge1d(int i, int j, int l, int r) {
        if (l == r) {
            Max[i][j] = max(Max[i*2][j], Max[i*2+1][j]);
            Min[i][j] = min(Min[i*2][j], Min[i*2+1][j]);
            return;
        }
        int m = (l + r) / 2;
        merge1d(i, j*2, l, m);
        merge1d(i, j*2+1, m+1, r);
    }
} tr;

main() {
#ifdef soytw
    freopen("in.txt","r",stdin);
#else

#endif
    int n,q;
    char cmd[3];
    while (scanf("%d",&n)==1) {
        FOR(i,1,n+1) {
            FOR(j,1,n+1) {
                scanf("%d",&tr.v);
                tr.x=i, tr.y=j;
                tr.update();
            }
        }
        scanf("%d",&q);
        while (q--) {
            scanf("%s",cmd);
            if (cmd[0]=='q') {
                // query
                scanf("%d%d%d%d", &tr.qt, &tr.ql, &tr.qb, &tr.qr);
                tr.query();
                printf("%d %d\n", tr.mx, tr.mn);
            } else {
                // update
                scanf("%d%d%d", &tr.x, &tr.y, &tr.v);
                tr.update();
            }
        }
    }
#ifdef soytw
    freopen("con","r",stdin);
    system("pause");
#endif
    return 0;
}
