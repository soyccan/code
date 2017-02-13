// poj2104
// persistent segtree
#include <bits/stdc++.h>
#define int long long
#define MS(s,v) memset(s,v,sizeof(s))
#define _FOR(i,start,end,step) for (int i=start; i!=end; i+=step)
#define FOR(i,start,end) for (int i=start; i<end; ++i)
using namespace std;
const long long INF = 0x3f3f3f3f3f3f3f3fLL;

struct SegTree {
    int sum;
    SegTree *lc, *rc;
    SegTree(int data=0) {
        lc = rc = nullptr;
        sum = data;
    }
    void update(int x, int v, int l, int r) {
        if (x == l && x == r) {
            sum += v;
            return;
        }
        down();
        int m = (l + r) >> 1;
        if (x <= m) lc->update(x, v, l, m);
        else rc->update(x, v, m+1, r);
        up();
    }
    int query(int ql, int qr, int k, int l, int r) {
        if (l == r) return l;
        down();
        int m = (l + r) >> 1;
        if (k <= lc->sum) return lc->query(ql, qr, k, l, m);
        else return rc->query(ql, qr, k - lc->sum, m+1, r);
        up();
    }
    void down() {
        if (lc == nullptr) lc = new SegTree;
        if (rc == nullptr) rc = new SegTree;
    }
    void up() {
        sum = lc->sum + rc->sum;
    }
};

int A[100002];
int B[100002];
main() {
#ifdef soytw
    freopen("in.txt","r",stdin);
#else
    ios::sync_with_stdio(0);
    cin.tie(0);
#endif
    int n,q,l,r,k;
    while (cin>>n>>q) {
        // Discretization, a.k.a. "LI SAN HUA"
        FOR(i,1,n+1) cin>>A[i];
        sort(A+1,A+n+1);
        int cnt = B[1] = 1;
        FOR(i,2,n+1) {
            if (A[i]>A[i-1]) cnt++;
            B[i]=cnt;
        }

        SegTree T;
        FOR(i,1,n+1) {
            T.update(B[i],1,1,n);
        }
        while (q--) {
            cin>>l>>r>>k;
            int p=T.query(l,r,k,1,n);
            cout<<A[p]<<'\n';
        }
    }
#ifdef soytw
    freopen("con","r",stdin);
    system("pause");
#endif
    return 0;
}
