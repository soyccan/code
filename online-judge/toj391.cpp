// toj 391
// segment tree (segmental modulo)
#include <cstdio>
#include <algorithm>
using namespace std;

struct SegTree {
    int* _a; // segment maximum array
    int _sz;

    SegTree(int sz) {
        _sz = sz;
        _a = new int[sz*4+2]();
    }

    void up(int i) {
        _a[i] = max(_a[i*2], _a[i*2+1]);
    }

    void _add(int i, int l, int r, int idx, int val) { // arr[idx] += val
        if (l == r)
            _a[i] += val;
        else {
            int m = (l + r) / 2;
            if (idx <= m) _add(i*2, l, m, idx, val);
            else _add(i*2+1, m+1, r, idx, val);
            up(i);
        }
    }

    void add(int idx, int val) {
        _add(1, 0, _sz-1, idx, val);
    }

    void _mod(int i, int l, int r, int from, int to, int val) { // arr[from:to] %= val
        if (_a[i] < val) return;
        if (from <= l && r <= to && l == r)
            _a[i] %= val;
        else {
            int m = (l + r) / 2;
            if (from <= m) _mod(i*2, l, m, from, to, val);
            if (to > m) _mod(i*2+1, m+1, r, from, to, val);
            up(i);
        }
    }

    void mod(int from, int to, int val) {
        _mod(1, 0, _sz-1, from, to, val);
    }

    int getmax() {
        return _a[1];
    }
};

int main() {
    int n, m, k, l, r, v;
    scanf("%d", &n);
    SegTree T(n);
    for (int i=0; i<n; i++) {
        scanf("%d", &v);
        T.add(i, v);
    }

    scanf("%d", &m);
    while (m--) {
        scanf("%d", &k);
        if (k == 1) {
            scanf("%d %d", &v, &l);
            T.add(l, v);
        }
        else if (k == 2) {
            scanf("%d %d %d", &l, &r, &v);
            T.mod(l, r, v);
        }
        else {
            printf("%d\n", T.getmax());
        }
    }
    return 0;
}
