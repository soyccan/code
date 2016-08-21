// uva1194
// bipartite matching
#include <bits/stdc++.h>
using namespace std;

vector<int> G[10000];
int match[10000];
bool used[10000];

bool dfs(int x) {
    for (int y : G[x]) {
        if (used[y]) continue;
        used[y] = true;
        if (match[y] == -1 || dfs(match[y])) {
            match[y] = x;
            return true;
        }
    }
    return false;
}

int main() {
    int n,m,k,i,x,y;
    while (cin>>n && n) {
        cin>>m>>k;
        for (int i=0; i<n; i++) G[i].clear();
        while (k--) {
            cin>>i>>x>>y;
            if (x==0 || y==0) continue;
            G[x].push_back(y);
        }
        int ans=0;
        memset(match, -1, sizeof match);
        for (int i=0; i<n; i++) {
            memset(used, 0, sizeof used);
            if (dfs(i)) ans++;
        }
        cout<<ans<<endl;
    }
    return 0;
}
