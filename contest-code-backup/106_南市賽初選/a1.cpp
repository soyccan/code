#include <bits/stdc++.h>
#define int long long
#define MS(s,v) memset(s,v,sizeof(s))
#define FOR(i,end) for (int i=0; i<end; ++i)
#define FOR1(i,end) for (int i=1; i<=end; ++i)
using namespace std;
const long long INF = 0x3f3f3f3f3f3f3f3fLL;

struct Pt { int x, y; };
Pt P[10005];

int cross(Pt a, Pt b) {
	return a.x * b.y - a.y * b.x;
}

void convex(int n) {
	sort(P, P+n, [](Pt a,Pt b) {
		if (a.x != b.x) return a.x < b.x;
		else return a.y < b.y;
	});
	vector<Pt> v;
	v.push_back(P[0]);
	for (int i=1; i<n; i++) {
		while (cross(v.back(), P[i]) < 0) v.pop_back();
		v.push_back(P[i]);
	}

	for (Pt k : v) cout << k.x << ' '<<k.y<<endl;
	// return v;
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
    P.push_back(Pt{x1, y1});
    P.push_back(Pt{x1, y2});
    P.push_back(Pt{x2, y1});
    P.push_back(Pt{x2, y2});
    P.push_back(Pt{xx, yy});

#ifdef soytw
    freopen("con","r",stdin);
    system("pause");
#endif
    return 0;
}