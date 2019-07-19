#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

struct Edge {
  int v, w;
  int len;
  bool operator<(Edge e) {
    return len<e.len;
  }
};

vector<Edge> ed;
int pa[1000];

int find(int p) {
  if (pa[p] != p)
    pa[p] = find(pa[p]);
  return pa[p];
}

int main() {
  int t,n;

  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);

    ed.clear();
    for (int i=0; i<n; i++)
      for (int j=0; j<n; j++) {
        Edge e;
        e.v = i;
        e.w = j;
        scanf("%d", &e.len);
        ed.push_back(e);
    }
    sort(ed.begin(), ed.end());

    for (int i=0; i<n; i++)
      pa[i] = i;

    int ans = 0;
    for (int i=0; i<ed.size(); i++) {
      Edge e = ed[i];
      if (find(e.v) != find(e.w)) {
        pa[find(e.v)] = find(e.w);
        ans = max(ans, e.len);
      }
    }
    printf("%d\n", ans);
  }

  return 0;
}