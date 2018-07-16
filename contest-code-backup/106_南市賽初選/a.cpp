#include <bits/stdc++.h>
#define int long long
#define MS(s,v) memset(s,v,sizeof(s))
#define FOR(i,end) for (int i=0; i<end; ++i)
#define FOR1(i,end) for (int i=1; i<=end; ++i)
using namespace std;
const long long INF = 0x3f3f3f3f3f3f3f3fLL;

struct Pt { 
    int x, y; 
    Pt(int x,int y): x(x), y(y) {}
};
Pt operator-(Pt a, Pt b) {return Pt(a.x-b.x, a.y-b.y);}
int cross(Pt a, Pt b) {
    return a.x * b.y - a.y * b.x;
}
double area(Pt a, Pt b, Pt c) {
    return abs(cross(b-a, c-a)/2.0);
}

main() {
#ifdef soytw
    freopen("in.txt","r",stdin);
#else
    ios::sync_with_stdio(0);
    cin.tie(0);
#endif

    int x1,y1,x2,y2,xx,yy;
    cin>>x1>>y1>>x2>>y2>>xx>>yy;
    // vector<Pt> v { 
    //     Pt{x1, y1},
    //     Pt{x1, y2},
    //     Pt{x2, y1},
    //     Pt{x2, y2}
    // };
    double sum = (x2-x1)*(y2-y1);
    if (x1 <= xx && xx <= x2 &&
        y1 <= yy && yy <= y2);
  
    else if ((xx > x2 && yy > y2) || (xx < x1 && yy < y1))
        sum/=2, sum+=area(Pt(xx,yy), Pt(x1,y2), Pt(x2,y1));
    else if ((xx > x2 && yy < y1) || (xx < x1 && yy > y2))
        sum/=2, sum+=area(Pt(xx,yy), Pt(x1,y1), Pt(x2,y2));
    else if (xx < x1)
        sum+=area(Pt(xx,yy), Pt(x1,y1), Pt(x1,y2));
    else if (xx > x2)
        sum+=area(Pt(xx,yy), Pt(x2,y1), Pt(x2,y2));
    else if (yy < y1)
        sum+=area(Pt(xx,yy), Pt(x1,y1), Pt(x2,y1));
    else if (yy > y2)
        sum+=area(Pt(xx,yy), Pt(x1,y2), Pt(x2,y2));


    // for (int i=0; i<v.size(); i++)
    //     if (v[i].x / xx == v[i].y / yy > 0)


    // // for (Pt e : v) cout<<e.x<<' '<<e.y<<endl;

    // sort(v.begin(), v.end(), [](Pt a, Pt b) {
    //     return atan2(a.y,a.x) < atan2(b.y,b.x);
    //     // return a.y/a.x < b.y/b.x;
    //     // if (a.x != b.x) return a.x < b.x;
    //     // else return a.y < b.y;
    // });

    // int sum = 0;
    // for (int i=0; i<v.size(); i++) {
    //     sum += cross(v[i], v[(i+1) % v.size()]);
    //     // cout << sum << '\n';
    // }
    cout << fixed << setprecision(1) << sum << '\n';

#ifdef soytw
    freopen("con","r",stdin);
    system("pause");
#endif
    return 0;
}