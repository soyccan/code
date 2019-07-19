// uva10245 closest pair
#include <bits/stdc++.h>
#define FOR(i,a,n) for (int i=a; i<n; i++)
using namespace std;

struct Point {
    double x, y;
} P[10020];

double dis(Point p, Point q) {
    return sqrt((p.x-q.x)*(p.x-q.x) + (p.y-q.y)*(p.y-q.y));
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
        sort(P, P+n, [](Point p, Point q) {return p.x < q.x;});

        double dmin = 1e9;
        FOR(i,0,n) {
            FOR(j,i+1,n) {
                // cout<<"Pi=("<<P[i].x<<','<<P[i].y<<") Pj=("<<P[j].x<<","<<P[j].y<<")\n";
                if (P[j].x - P[i].x > dmin) break;
                dmin = min(dmin, dis(P[i], P[j]));
            }
        }

        if (dmin < 10000)
            cout << fixed << setprecision(4) << dmin << '\n';
        else
            cout << "INFINITY" << '\n';
    }

    return 0;
}
