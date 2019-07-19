// soytw

#include <cstdio>
#include <cassert>
#include <algorithm>
#define FOR(i, a, N) for (int i=a; i<N; i++)
using namespace std;

double A[40][40];
int N;

inline int sgn(double x) {
    const double EPS = 1e-10;
    if (-EPS <= x && x <= EPS)
        return 0;
    else if (x > EPS)
        return 1;
    else
        return -1;
}

bool gauss() {
    FOR(i, 0, N) {
        int p = i;
        double mx = abs(A[i][i]);
        FOR(j, i+1, N)
            if (abs(A[j][i]) > mx)
                p = j,
                mx = abs(A[j][i]);
        if (sgn(mx) == 0)
            return false;
        if (p != i)
            FOR(k, 0, N)
                swap(A[p][k], A[i][k]);
        FOR(j, i+1, N) {
            double c = A[j][i] / A[i][i];
            FOR(k, 0, N)
                A[j][k] -= c * A[i][k];
        }

        FOR(i, 0, N) {
            FOR(j, 0, N)
                printf("%+.9lf ", A[i][j]);
            putchar('\n');
        }
        putchar('\n');
    }
    return true;
}

int main() {
    freopen("in.txt", "r", stdin);
    int t;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &N);
        FOR(i, 0, N)
            FOR(j, 0, N)
                scanf("%lf", &A[i][j]);
        bool ans = true;
        if (gauss())
            FOR(i, 0, N)
                ans &= (bool) sgn(A[i][i]);
        else
            ans = false;
        puts(ans ? "YES" : "NO");
    }
    return 0;
}
