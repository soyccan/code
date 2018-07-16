//toj365
#include <bits/stdc++.h>
// #define int long long
using namespace std;
struct Node {
    int len,lb,rb,l,r;
    // lb/rb: bounds of longest happy sequence
    Node *lc,*rc;
    Node(): lc(0),rc(0),len(-1),lb(-1),rb(-1),l(-1),r(-1) {}
    void up() {
        if (lc->rb==lc->r && rc->lb==rc->l)
            len=lc->len+rc->len,
            lb=lc->lb,
            rb=rc->rb;
        else if (lc->len > rc->len) ///
            len=lc->len,
            lb=lc->lb;
            rb=lc->rb;
        else
            len=rc->len,
            lb=rc->lb;
            rb=rc->rb;
    }
    void update(int i,int v) {
        int m=(l+r)/2;
        if (l==i && r==i) len=1, lb=rb=i;
        else if (i<=m) lc->update(l,m,i,v);
        else if (i>m) rc->update(m+1,r,i,v);
        up();
    }
    int query(int ql,int qr) {
        int m=(l+r)/2;
        if (ql<=l && r<=qr) return len;
        else {
            if (ql<=m)
        }
    }
};
void build(Node* nd,int l,int r) {
    nd->lc = new Node();
    nd->rc = new Node();
    nd->l = l;
    nd->r = r;
    if (l==r) return;
    int m=(l+r)/2;
    build(nd->lc,l,m);
    build(nd->rc,m+1,r);
}
main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("in.txt","r",stdin);
    int n,q,c,a,b,x;
    cin>>n;
    Node* rt = new Node();
    build(rt,1,n);
    for (int i=1; i<=n; i++) {
        cin>>x;
        rt->update(1,n,i,x);
    }
    cin>>q;
    while (q--) {
        cin>>c>>a>>b;
        if (c==1) rt->update(1,n,a,b);
        else cout<<rt->query(1,n,a,b)<<'\n';
    }
    return 0;
}
