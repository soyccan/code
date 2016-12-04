#include <bits/stdc++.h>
#define double long double
#define MS(s,v) memset(s,v,sizeof(s))
#define FOR(i,st,en) for (int i=st; i<en; i++)
#define RFOR(i,st,en) for (int i=st; i>en; i--)
using namespace std;
typedef complex<double> Vector;
typedef complex<double> Point;
struct Line {
    Point p;
    Vector v;
    Line(Point p,Vector v): p(p),v(v) {}
};
Point poly[100005];
const double EPS = 1e-10;
const int INF = 1e9;
double dot(Vector a,Vector b) { return real(conj(a)*b); }
double cross(Vector a,Vector b) { return imag(conj(a)*b); }
int inter(Line l,Point a,Point b) {
    double t = cross(l.v, a-l.p);
    double k = cross(l.v, b-l.p);
    if (t==0 && k==0)
        return INF;
    else if (t*k < EPS) // <=0
        return 1;
    else // >0
        return 0;
}
Point getinter(Line l,Point a,Point b) {
    return l.p + l.v * cross(a-l.p, b-a) / cross(l.v, b-a);
}
main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    // freopen("254/res/testdata/38.in","r",stdin);
    int a,b,c,d,n;
    while (cin>>a>>b>>c>>d>>n) {
        Line ln(Point(a,b),Vector(c-a,d-b));
        vector<Point> pt;
        FOR(i,0,n) {
            int x,y;
            cin>>x>>y;
            poly[i]=Point(x,y);
        }
        poly[n]=poly[0];
        double ans=0;
        FOR(i,0,n) {
            if (inter(ln,poly[i],poly[i+1])==1)
                pt.push_back(getinter(ln,poly[i],poly[i+1]));
            // cout<<"ans:"<<ans<<'\n';
            // cout<<poly[i]<<poly[i+1]<<getinter(ln,poly[i],poly[i+1])<<endl;
        }
        sort(pt.begin(), pt.end(), [](Point a,Point b) {
            return cross(Point(0,0),a) < cross(Point(0,0),b);
        });
        pt.erase(unique(pt.begin(), pt.end(), [](Point a,Point b) {
            return abs(a.real()-b.real())<EPS && abs
        }), pt.end());
        FOR(i,1,pt.size()) {
            ans+=norm(pt[i]-pt[i-1]);
            cout<<"ans:"<<ans<<pt[i]<<pt[i-1]<<'\n';
        }
        cout<<fixed<<setprecision(2)<<sqrt(ans)<<'\n';
    }
    return 0;
}
