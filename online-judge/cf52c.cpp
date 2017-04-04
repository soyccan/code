// cf53c
// segment tree with segmental modification and range minimum query
#include <bits/stdc++.h>
#define int long long
#define MS(s,v) memset(s,v,sizeof(s))
#define _FOR(i,start,end,step) for (int i=start; i!=end; i+=step)
#define FOR(i,start,end) for (int i=start; i<end; ++i)
using namespace std;
const long long INF = 0x3f3f3f3f3f3f3f3fLL;

struct SegTree {
    int mn, inc;
    SegTree *lc,*rc;
    SegTree(): mn(INF), inc(0), lc(nullptr), rc(nullptr) {}
    void build(int arr[], int l, int r) {
        if (l == r) {
            this->mn = arr[l];
            return;
        }
        this->down();
        int m = (l + r) / 2;
        lc->build(arr, l, m);
        rc->build(arr, m+1, r);
        this->up();
        // printf("l%lld r%lld mn%lld\n",l,r,mn);
    }
    void add(int ql, int qr, int v, int l, int r) {
        // printf("a ql%lld qr%lld l%lld r%lld mn%lld\n",ql,qr,l,r,mn);
        if (ql<=l && r<=qr) {
            this->mn += v;
            this->inc += v;
            return;
        }
        this->down();
        int m = (l + r) / 2;
        if (ql <= m) lc->add(ql, qr, v, l, m);
        if (qr > m) rc->add(ql, qr, v, m+1, r);
        this->up();
    }
    void query(int ql, int qr, int l, int r, int& mn) {
        // printf("q ql%lld qr%lld l%lld r%lld mn%lld\n",ql,qr,l,r,this->mn);
        if (ql<=l && r<=qr) {
            mn = min(mn, this->mn);
            return;
        }
        this->down();
        int m = (l + r) / 2;
        if (ql <= m) lc->query(ql,qr,l,m,mn);
        if (qr > m) rc->query(ql,qr,m+1,r,mn);
        this->up();
    }
    void down() {
        if (lc == nullptr) lc = new SegTree();
        if (rc == nullptr) rc = new SegTree();
        if (this->inc) {
            lc->mn += this->inc;
            rc->mn += this->inc;
            lc->inc += this->inc;
            rc->inc += this->inc;
            this->inc = 0;
        }
    }
    void up() {
        this->mn = min(lc->mn, rc->mn);
    }
};

int A[400005];
main() {
#ifdef soytw
    freopen("in.txt","r",stdin);
#else
    ios::sync_with_stdio(0);
    cin.tie(0);
#endif
    int n,q; string s;
    while (cin>>n) {
        FOR(i,0,n) cin>>A[i];
        SegTree* root = new SegTree();
        root->build(A,0,n-1);
        cin>>q;
        cin.ignore(1,'\n');
        while (q--) {
            getline(cin,s);
            stringstream ss(s);
            int v[3], i=0;
            while (ss>>v[i] && ++i);
            if (i==3) {
                // increase
                if (v[0] <= v[1])
                    root->add(v[0],v[1],v[2],0,n-1);
                else {
                    root->add(v[0],n-1,v[2],0,n-1);
                    root->add(0,v[1],v[2],0,n-1);
                }
            } else {
                // rmq
                int mn = INF;
                if (v[0] <= v[1])
                    root->query(v[0],v[1],0,n-1,mn);
                else {
                    root->query(v[0],n-1,0,n-1,mn);
                    root->query(0,v[1],0,n-1,mn);
                }
                cout<<mn<<'\n';
            }
        }
    }
#ifdef soytw
    freopen("con","r",stdin);
    system("pause");
#endif
    return 0;
}
