// uva11297
// 2d segment tree
#include <bits/stdc++.h>
// #define int long long
#define MS(s,v) memset(s,v,sizeof(s))
#define _FOR(i,start,end,step) for (int i=start; i!=end; i+=step)
#define FOR(i,start,end) for (int i=start; i<end; ++i)
using namespace std;
// const long long INF = 0x3f3f3f3f3f3f3f3fLL;
const int INF = INT_MAX;

struct SegTree {
    int mx, mn;
    SegTree *lc, *rc;
    SegTree(): mx(-INF), mn(INF), lc(nullptr), rc(nullptr) {}
    inline void build(int* a, int l, int r) {
        if (l == r) {
            mx = mn = a[l];
            return;
        }
        lc = new SegTree;
        rc = new SegTree;
        int m = (l + r) / 2;
        lc->build(a, l, m);
        rc->build(a, m+1, r);
        up();

        // printf("b l%d r%d mx%d mn%d\n",l,r,mx,mn);
    }
    inline void update(int* a, int x, int v, int l, int r) {
        if (l == x && x == r) {
            a[x] = v;
            mx = max(mx, a[x]);
            mn = min(mn, a[x]);
            return;
        }
        int m = (l + r) / 2;
        if (x <= m) lc->update(a, x, v, l, m);
        else rc->update(a, x, v, m+1, r);
        up();
    }
    inline void query(int ql, int qr, int l, int r, int& mx, int& mn) {
        // printf("q l%d r%d mx%d mn%d\n",l,r,this->mx,this->mn);
        if (ql <= l && r <= qr) {
            mx = max(mx, this->mx);
            mn = min(mn, this->mn);
            return;
        }
        int m = (l + r) / 2;
        if (ql <= m) lc->query(ql, qr, l, m, mx, mn);
        if (qr > m) rc->query(ql, qr, m+1, r, mx, mn);
        up();
        // printf("q l%d r%d mx%d mn%d\n",l,r,this->mx,this->mn);
    }
    inline void up() {
        mx = max(lc->mx, rc->mx);
        mn = min(lc->mn, rc->mn);
    }
};
inline SegTree* merge(SegTree* a, SegTree* b, int l, int r) {
    SegTree* c = new SegTree;
    c->mx = max(a->mx, b->mx);
    c->mn = min(a->mn, b->mn);
    if (l == r) return c;
    int m = (l + r) / 2;
    c->lc = merge(a->lc, b->lc, l, m);
    c->rc = merge(a->rc, b->rc, m+1, r);
    return c;
}
struct SegTree2D {
    SegTree *st;
    SegTree2D *tc, *bc;
    SegTree2D(): st(nullptr), tc(nullptr), bc(nullptr) {}
    inline void build(int** a, int t, int b, int l, int r) {
        if (t == b) {
            st = new SegTree;
            st->build(a[t], l, r);
            return;
        }
        tc = new SegTree2D;
        bc = new SegTree2D;
        int m = (t + b) / 2;
        tc->build(a, t, m, l, r);
        bc->build(a, m+1, b, l, r);
        st = merge(tc->st, bc->st, l, r);
        // printf("B t%d b%d l%d r%d\n",t,b,l,r);
    }
    inline void update(int** a, int x, int y, int v, int t, int b, int l, int r) {
        if (t == x && x == b) {
            st->update(a[x], y, v, l, r);
            return;
        }
        int m = (t + b) / 2;
        if (x <= m) tc->update(a, x, y, v, t, m, l, r);
        else bc->update(a, x, y, v, m+1, b, l, r);
        st = merge(tc->st, bc->st, l, r);
    }
    inline void query(int qt, int qb, int ql, int qr, int t, int b, int l, int r, int& mx, int& mn) {
        // printf("Q t%d b%d l%d r%d mx%d mn%d\n",t,b,l,r,mx,mn);
        if (qt <= t && b <= qb) {
            st->query(ql, qr, l, r, mx, mn);
            return;
        }
        int m = (t + b) / 2;
        if (qt <= m) tc->query(qt, qb, ql, qr, t, m, l, r, mx, mn);
        if (qb > m) bc->query(qt, qb, ql, qr, m+1, b, l, r, mx, mn);
        // st = merge(tc->st, bc->st, l, r);
        // printf("Q t%d b%d l%d r%d mx%d mn%d\n",t,b,l,r,mx,mn);
    }
};

main() {
#ifdef soytw
    freopen("in.txt","r",stdin);
#else

#endif
    int n,q,a,b,c,d;
    char cmd[3];
    SegTree2D* root;
    int** A;
    while (scanf("%d",&n)==1) {
        A = new int*[n+1];
        FOR(i,1,n+1) {
            A[i] = new int[n+1];
            FOR(j,1,n+1) scanf("%d",&A[i][j]);
        }
        root = new SegTree2D;
        root->build(A,1,n,1,n);
        scanf("%d",&q);
        while (q--) {
            scanf("%s %d %d %d",cmd,&a,&b,&c);
            if (cmd[0]=='q') {
                // query
                scanf("%d",&d);
                int mx=-INF, mn=INF;
                root->query(a,c,b,d,1,n,1,n,mx,mn);
                printf("%d %d\n",mx,mn);
            } else {
                // update
                root->update(A,a,b,c,1,n,1,n);
            }
        }
    }
#ifdef soytw
    freopen("con","r",stdin);
    system("pause");
#endif
    return 0;
}
