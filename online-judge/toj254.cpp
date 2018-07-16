// toj254
// computational geometry
#include <bits/stdc++.h>
#define double long double
#define MS(s,v) memset(s,v,sizeof(s))
#define FOR(i,st,en) for (int i=st; i<en; i++)
#define x real()
#define y imag()
using namespace std;
typedef complex<double> Vector;
typedef complex<double> Point;
struct Line {
    Point p;
    Vector v;
    Line(Point p,Vector v): p(p),v(v) {}
};
Point poly[100005];
const int INF = 1e9;
double dot(Vector a,Vector b) { return (conj(a)*b).x; }
double cross(Vector a,Vector b) { return (conj(a)*b).y; }
int inter(Line l,Point a,Point b) {
    double t = cross(l.v, a-l.p);
    double k = cross(l.v, b-l.p);
    if (t==0 && k==0)
        return INF;
    else if (t*k <= 0)
        return 1;
    else
        return 0;
}
Point getinter(Line l,Point a,Point b) {
    return l.p + l.v * cross(a-l.p, b-a) / cross(l.v, b-a);
}
bool inpoly(int n,Point p) {
    int cnt=0;
    Line ray(p,Vector(INF,0));
    FOR(i,0,n) {
        Point a=poly[i], b=poly[(i+1)%n];
        if (cross(a-p,b-p)==0 && dot(a-p,b-p)<=0) return 1; // on side
        if (inter(ray,a,b)==1 && getinter(ray,a,b).x>=p.x && getinter(ray,a,b)!=a) cnt++;
    }
    return cnt%2==1;
}
main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int a,b,c,d,n;
    while (cin>>a>>b>>c>>d>>n) {
        Line ln(Point(a,b),Vector(c-a,d-b));
        vector<Point> is; // intersections
        FOR(i,0,n) {
            double tx,ty;
            cin>>tx>>ty;
            poly[i]=Point(tx,ty);
        }
        double ans=0;
        FOR(i,0,n)
            if (inter(ln,poly[i],poly[(i+1)%n])==1)
                is.push_back(getinter(ln,poly[i],poly[(i+1)%n]));
        sort(is.begin(), is.end(), [](Point a,Point b) {
            if (a.x!=b.x) return a.x<b.x;
            else return a.y<b.y;
        });
        is.erase(unique(is.begin(), is.end()), is.end());
        FOR(i,1,(int)is.size())
            if (inpoly(n,(is[i]+is[i-1])/2.0L))
                ans+=abs(is[i]-is[i-1]);
        cout<<fixed<<setprecision(2)<<ans<<'\n';
    }
    return 0;
}
