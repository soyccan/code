// soytw

#include <cstdio>
#include <cassert>
#include <algorithm>
#define FOR(i, a, N) for (int i=a; i<N; i++)
#define int long long // will overflow !!!
using namespace std;

int A[40][40];
int N;

bool gauss() {
    FOR(i, 0, N) {
        int p = i;
        while (A[p][i] == 0 && p < N) p++;
        if (p == N) return false;
        if (p != i)
            FOR(k, 0, N)
                swap(A[p][k], A[i][k]);
        FOR(j, i+1, N) {
            for (;;) {
                assert(A[i][i] != 0);
                int c = A[j][i] / A[i][i];
                FOR(k, 0, N)
                    A[j][k] -= c * A[i][k];

                if (A[j][i] == 0) break;
                FOR(k, 0, N)
                    swap(A[j][k], A[i][k]);

            }
        }
    }
    return true;
}

int32_tmain() {
    freopen("in.txt", "r", stdin);
    int t;
    scanf("%lld", &t);
    while (t--) {
        scanf("%lld", &N);
        FOR(i, 0, N)
            FOR(j, 0, N)
                scanf("%lld", &A[i][j]);
        bool ans = true;
        if (gauss())
            FOR(i, 0, N)
                ans &= (bool)A[i][i];
        else
            ans = false;
        FOR(i, 0, N) {
            FOR(j, 0, N)
                printf("%+2lld ", A[i][j]);
            putchar('\n');
        }
        putchar('\n');
        // int prod = 1;
        // FOR(i, 0, N) prod *= A[i][i];
        // printf("%lld\n", prod); // 21474836480
        puts(ans ? "YES" : "NO");
    }
    return 0;
}
