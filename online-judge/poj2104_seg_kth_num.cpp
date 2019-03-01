// segment k-th number
// poj 2104

#include <cstdio>
#include <cassert>
#include <climits>
#include <algorithm>
#define FOR(i, a, n) for (int i=a; i<n; i++)
#define PII pair<int, int>
using namespace std;

int TR[20][112345];
int A[112345];

PII operator+=(PII& a, const PII& b) {
    a.first += b.first;
    a.second += b.second;
    return a;
}

void build(int no, int l, int r) {
    if (l == r) {
        TR[no][l] = A[l];
        return;
    }
    int m = (l + r) >> 1;
    build(no + 1, l, m);
    build(no + 1, m + 1, r);

    int a = l, b = m + 1, i=l;
    while (i <= r) {
        if ( b > r || (a <= m && TR[no+1][a] < TR[no+1][b]) )
            TR[no][i++] = TR[no+1][a++];
        else if ( b <= r )
            TR[no][i++] = TR[no+1][b++];
    }

    // printf("no=%d l=%d r=%d\nTR:", no, l, r);
    // FOR(i, l, r+1) printf("%d ", TR[no][i]);
    // putchar('\n');
}

PII query(int no, int l, int r, int ql, int qr, int k) {
    // return (a,b) where:
    // a = the number of items that is less than k
    // b = the number of items that is less than or equal to k

    int m = (l + r) >> 1;
    PII ret = make_pair(0, 0);
    if (ql <= l && r <= qr) {
        ret.first = lower_bound(&TR[no][l], &TR[no][r+1], k) - &TR[no][l];
        ret.second = upper_bound(&TR[no][l], &TR[no][r+1], k) - &TR[no][l];
    }
    else {
        if (ql <= m)
            ret += query(no+1, l, m, ql, qr, k);

        if (qr > m)
            ret += query(no+1, m+1, r, ql, qr, k);
    }

    // printf("no=%d l=%d r=%d ql=%d qr=%d k=%d ret=%d\nTR:", no, l, r, ql, qr, k, ret);
    // FOR(i, l, r+1) printf("%d ", TR[no][i]);
    // putchar('\n');
    return ret;
}

int main() {
#ifdef soyccan
    freopen("in.txt", "r", stdin);
#endif
    int n, q;
    while (scanf("%d %d", &n, &q) == 2) {
        FOR(i, 1, n+1) scanf("%d", &A[i]);
        build(0, 1, n);
        while (q--) {
            int ql, qr, k;
            scanf("%d %d %d", &ql, &qr, &k);

            long long l = INT_MIN, r = INT_MAX;
            while (l < r) {
                int m = (l + r) >> 1;
                if (m + 1 <= r)
                    m++; // +1 to prevent loop during binary search
                PII res = query(0, 1, n, ql, qr, m);
                // printf("l=%lld r=%lld m=%d res=(%d,%d)\n", l, r, m, res.first, res.second);
                if (res.first < k && k <= res.second)
                    l = m;
                else if (res.second < k)
                    l = m + 1;
                else if (res.first > k-1)
                    r = m - 1;
            }
            assert(l == r);
            PII res = query(0, 1, n, ql, qr, l);
            assert(res.first < k && k <= res.second);
            printf("%lld\n", l);
        }
    }
    return 0;
}
