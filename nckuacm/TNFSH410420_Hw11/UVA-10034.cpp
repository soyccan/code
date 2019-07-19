#include <bits/stdc++.h>
using namespace std;
 
struct Point {
  double x, y;
  bool operator!=(Point p) {
    return (x!=p.x || y!=p.y);
  }
  bool operator<(Point p) const {
    if (x!=p.x)
      return (x<p.x);
    else
      return (y<p.y);
  }
};
 
struct Edge {
  Point v, w;
  double len;
  bool operator<(Edge e) {
    return len<e.len;
  }
};
 
Point pt[200];
vector<Edge> ed;
map<Point, Point> pa;
 
Point find(Point p) {
  if (pa[p] != p)
    pa[p] = find(pa[p]);
  return pa[p];
}
 
double dis(Point p, Point q) {
  return sqrt(pow(p.x-q.x, 2) + pow(p.y-q.y, 2));
}
 
int main() {
  int t,n;
 
  cin>>t;
  while (t--) {
    cin>>n;
 
    ed.clear();
    for (int i=0; i<n; i++) {
      cin >> pt[i].x >> pt[i].y;
      for (int j=i-1; j>=0; j--)
        ed.push_back({pt[i], pt[j], dis(pt[i], pt[j])});
    }
    sort(ed.begin(), ed.end());
 
    pa.clear();
    for (int i=0; i<n; i++)
      pa[pt[i]] = pt[i];
 
    double ans = 0;
    for (Edge e : ed) {
      if (find(e.v) != find(e.w)) {
        pa[find(e.v)] = find(e.w);
        ans += e.len;
      }
    }
    printf("%.2f\n", ans);
    if (t>0) cout<<'\n';
  }
 
  return 0;
}