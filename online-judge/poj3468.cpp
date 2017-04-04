// poj3468
// segment tree with lazy flag
#include <iostream>
#include <string>
#include <utility>
#define int long long
using namespace std;
struct Node {
    int l, r, add, sum;
};
int arr[100005];
Node seg[400005];
inline void pushup(int i) {
    seg[i].sum = seg[i*2].sum + seg[i*2+1].sum;
}
inline void pushdown(int i) {
    if (seg[i].add) {
        seg[i*2].sum += seg[i].add * (seg[i*2].r-seg[i*2].l+1);
        seg[i*2+1].sum += seg[i].add * (seg[i*2+1].r-seg[i*2+1].l+1);
        seg[i*2].add += seg[i].add;
        seg[i*2+1].add += seg[i].add;
        seg[i].add = 0;
    }
}
inline void build(int i, int l, int r) {
    seg[i].l = l;
    seg[i].r = r;
    seg[i].add = 0;
    if (l == r)
        seg[i].sum = arr[l];
    else {
        int m = (l+r)/2;
        build(i*2, l, m);
        build(i*2+1, m+1, r);
        pushup(i);
    }
}
inline void add(int i, int l, int r, int v) {
    if (l <= seg[i].l && seg[i].r <= r) {
        seg[i].sum += v * (seg[i].r - seg[i].l + 1);
        seg[i].add += v;
    } else {
        int m = (seg[i].l + seg[i].r)/2;
        pushdown(i);
        if (l <= m)
            add(i*2, l, r, v);
        if (r > m)
            add(i*2+1, l, r, v);
        pushup(i);
    }
}
inline int sum(int i, int l, int r) {
    if (l <= seg[i].l && seg[i].r <= r)
        return seg[i].sum;
    else {
        int m = (seg[i].l + seg[i].r)/2;
        int res = 0;
        pushdown(i);
        if (l <= m)
            res += sum(i*2, l, r);
        if (r > m)
            res += sum(i*2+1, l, r);
        return res;
    }
}
main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    string cmd;
    int n,q,a,b,v;
    cin>>n>>q;
    for (int i=1; i<=n; i++)
        cin>>arr[i];
    build(1,1,n);
    while (q--) {
        cin>>cmd>>a>>b;
        if (a > b) swap(a,b);
        if (cmd[0] == 'C') {
            cin>>v;
            add(1,a,b,v);
        } else {
            cout<<sum(1,a,b)<<'\n';
        }
    }
    return 0;
}
