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
        for (int i=0; i<k; i++) {
            cin>>j>>x>>y;
            G[j].clear();
            G[j].push_back(x);
            G[j].push_back(y+200);
        }
        int ans=0;
        memset(used, 0, sizeof used);
        memset(match, -1, sizeof match);
        for (int i=0; i<k; i++)
            if (dfs(i)) ans++;
        cout<<ans<<endl;
    }
    return 0;
}
