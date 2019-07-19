#include <bits/stdc++.h>
using namespace std;

map<string, vector<string>> G;
map<string, int> dep;
map<string, int> low;
set<string> cam;

void dfs(string p, string pa) {
  int child = 0;
  for (string q : G[p]) {
    if (dep.find(q) == dep.end()) {
      low[q] = dep[q] = dep[p]+1;
      child++;
      dfs(q, p);
      low[p] = min(low[p], low[q]);
      if ((pa == "" && child > 1) || (pa != "" && low[q] >= dep[p]))
        cam.insert(p);
    } else if (q != pa) {
      low[p] = min(low[p], dep[q]);
    }
  }
}

int main() {
  int n, m, tc=1;
  string a, b;
  while (cin >> n && n != 0) {
    G.clear();
    cam.clear();
    dep.clear();
    low.clear();
    while (n--)
      cin >> a;
    cin >> m;
    while (m--) {
      cin >> a >> b;
      G[a].push_back(b);
      G[b].push_back(a);
    }

    for (auto p : G)
      if (dep.find(p.first) == dep.end())
        dfs(p.first, "");
    if (tc > 1) cout << '\n';
    printf("City map #%d: %d camera(s) found\n", tc++, (int)cam.size());
    for (string c : cam)
      cout << c << '\n';
  }
  return 0;
}