// nctu 472
// brute force

#include <cstdio>
#include <cassert>
#include <cmath>
#include <algorithm>
#define FOR(i, a, n) for (int i=a; i<n; i++)
#define LL long long
using namespace std;

LL T[100], S[10][10];
int N;

int main() {
#ifdef soyccan
    freopen("in.txt", "r", stdin);
#endif
    for (;;) {
        N = 0;
        memset(T, 0, sizeof T);
        int c;
        for (;;) {
            c = getchar();
            if ('0' <= c && c <= '9')
                T[N] = T[N] * 10 + (c - '0');
            else if (c == ' ')
                N++;
            else if (c == '\n' || c == EOF)
                break;
            else
                assert(c != c);
        }
        if (c == EOF) break;

        N = sqrt(N);
        FOR(i, 0, N)
            FOR(j, 0, N)
                S[i][j] = T[i*N + j];

    }
    return 0;
}
