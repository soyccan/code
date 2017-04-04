// uva10652
// convex hull
#include <bits/stdc++.h>
#define double long double
#define MS(a,v) memset(a,v,sizeof a)
#define FOR(i,l,r) for (int i=l; i<=r; ++i)
#define RFOR(i,l,r) for (int i=l; i>=r; --i)
#define x real()
#define y imag()
using namespace std;
typedef complex<double> Point;
typedef complex<double> Vector;
Vector rotate(Vector v,double a) {
    a=a*acos(-1)/180;
    return Vector(v.x*cos(a)-v.y*sin(a), v.x*sin(a)+v.y*cos(a));
}
const double EPS = 1e-10;
double cross(Vector a,Vector b) { return (conj(a)*b).y - EPS; }
main() {
//    freopen("in.txt","r",stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t,n; double w,h,a,X,Y;
    cin>>t;
    while (cin>>n) {
        vector<Point> pt;
        double box=0;
        while (n--) {
            cin>>X>>Y>>w>>h>>a;
            Point c(X,Y);
            pt.push_back(c+rotate(Vector(w/2, h/2),-a));
            pt.push_back(c+rotate(Vector(w/2, -h/2),-a));
            pt.push_back(c+rotate(Vector(-w/2, h/2),-a));
            pt.push_back(c+rotate(Vector(-w/2, -h/2),-a));
            box+=w*h;
        }
        sort(pt.begin(),pt.end(), [](Point a,Point b) {
             if (a.x!=b.x) return a.x<b.x;
             else return a.y<b.y;
        });
        pt.erase(unique(pt.begin(),pt.end()),pt.end());
        vector<Point> ch; int sz;
        FOR(i,0,(int)pt.size()-1) {
            while ((sz=ch.size()) && cross(ch[sz-1]-ch[sz-2], pt[i]-ch[sz-1])<=0)
                ch.pop_back();
            ch.push_back(pt[i]);
        }
        RFOR(i,(int)pt.size()-2,1) {
            while ((sz=ch.size()) && cross(ch[sz-1]-ch[sz-2], pt[i]-ch[sz-1])<=0)
                ch.pop_back();
            ch.push_back(pt[i]);
        }
        double total=0;
        FOR(i,0,(int)ch.size()-1) total+=cross(ch[i],ch[(i+1)%ch.size()]);
        cout<<fixed<<setprecision(1)<<200*box/abs(total)<<" %\n";
    }
    return 0;
}
