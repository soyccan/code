// uva10245 closest pair
// divide and conquer
#include <bits/stdc++.h>
#define FOR(i,a,n) for (int i=a; i<n; i++)
using namespace std;

struct Point {
    double x, y;
} P[10020], tmp[10020];

double dis(Point p, Point q) {
    return sqrt((p.x-q.x)*(p.x-q.x) + (p.y-q.y)*(p.y-q.y));
}

double find_closest(int l, int r) {
    if (l >= r) return INFINITY;
    if (l + 1 == r) return dis(P[l], P[r]);
    int m = (l + r) / 2;
    double dmin = 1e9;
    dmin = min(dmin, find_closest(l, m));
    dmin = min(dmin, find_closest(m+1, r));

    int ll = l, rr = r;
    while (P[ll].x < P[m].x - dmin) ll++;
    while (P[rr].x > P[m+1].x + dmin) rr--;
    int n = rr - ll + 1;
    memcpy(tmp, P+ll, sizeof(Point) * n);
    sort(tmp, tmp+n, [](Point p, Point q) { return p.y<q.y; });
    FOR(i,0,n-1)
        FOR(j,i+1,i+4) {
            if (j >= n) break;
            dmin = min(dmin, dis(tmp[i], tmp[j]));
        }
    return dmin;
}

int main() {
#ifdef soytw
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
#else
    ios::sync_with_stdio(0);
    cin.tie(0);
#endif
    int n;
    while (cin>>n && n) {
        FOR(i,0,n) cin>>P[i].x>>P[i].y;
        sort(P, P+n, [](Point p, Point q) { return p.x < q.x; });

        double dmin = find_closest(0, n-1);
        if (dmin < 10000)
            cout << fixed << setprecision(4) << dmin << '\n';
        else
            cout << "INFINITY" << '\n';
    }

    return 0;
}
