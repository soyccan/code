// soytw

#include <cstdio>
#include <cstring>
#include <cassert>
#include <vector>
#include <algorithm>
#define FOR(i, a, n) for (int i=a; i<n; i++)
using namespace std;

int N;
int pa[212345];
vector<int> G[212345];
bool used[212345];

void dfs(int x, int t) {
    if (t == 0) return;
    // printf("x=%d t=%d\n", x, t);
    used[x] = true;
    for (int y : G[x])
        dfs(y, t-1);
}

int main() {
#ifdef soytw
    freopen("in.txt", "r", stdin);
#endif
    int k, x;
    scanf("%d %d", &N, &k);
    FOR(i, 2, N+1) {
        scanf("%d", &x);
        G[x].push_back(i);
        pa[i] = x;
    }

    int l = 1, r = N;
    while (l < r) {
        int t = (l + r) >> 1;
        vector<bool> fil(N+1);
        FOR(i, N-k+1, N+1) fil[i] = true;
        bool suc = false;
        do {
            memset(used, false, sizeof used);
            // printf("T=%d\n", t);
            FOR(i, 1, N+1)
                if (fil[i])
                    dfs(i, t);
            suc = true;
            FOR(i, 1, N+1)
                if (!used[i])
                    suc = false;
            if (suc)
                break;
        } while (next_permutation(fil.begin(), fil.end()));

        if (suc) r = t;
        else l = t+1;
    }
    assert(l == r);
    printf("%d\n", l);

    return 0;
}
