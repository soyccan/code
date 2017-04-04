// poj2289
// bipartite multiple matching
#include <iostream>
#include <vector>
#include <cstring>
#include <string>
#include <sstream>
using namespace std;
vector<int> G[10002];
vector<int> match[10002];
bool used[10002];
int N,M;
inline bool dfs(int x, int cap) {
    for (int j=0; j<G[x].size(); j++) {
        int y = G[x][j];
        if (!used[y]) {
            used[y] = true;
            // cout<<"match["<<y<<"]:"<<match[y].size()<<endl;
            if (match[y].size() < cap) {
                match[y].push_back(x);
                return true;
            }
            for (int i=0; i<match[y].size(); i++) {
                if (dfs(match[y][i],cap)) {
                    match[y][i] = x;
                    return true;
                }
            }
        }
    }
    return false;
}

inline int maxmatch(int cap) {
    for (int i=0; i<M; i++)
        match[i].clear();
    int res = 0;
    for (int i=0; i<N; i++) {
        memset(used,0,sizeof used);
        if (dfs(i,cap)) res++;
    }
    return res;
}

int main() {
    while (cin>>N>>M && N && M) {
        for (int i=0; i<N; i++) {
            G[i].clear();
            string s,name;
            scanf("\n");
            getline(cin,s);
            stringstream ss(s);
            ss>>name;
            int g;
            while (ss>>g)
                G[i].push_back(g);
        }

        ///
        // for (int i=0; i<N; i++) cout<<"  "<<G[i].size()<<endl;

        int l=0, r=N, ans=-1;
        while (l <= r) {
            int mid = (l+r)/2;
            if (maxmatch(mid) == N) {
                ans = mid;
                r = mid-1;
            }
            else
                l = mid+1;
        }
        cout<<ans<<'\n';
    }
    return 0;
}
