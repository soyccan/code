#include <bits/stdc++.h>
#define FOR(i, a, n) for (int i = a; i < n; i++)
using namespace std;

int A[1002];
int N;

int f(int b, int k) {
    int e=0, s=0;
    FOR(i,0,N)
        if (i % k != b % k) {
            if (A[i] == 1) e++;
            else if (A[i] == -1) s++;
        }
    return abs(e - s);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int k,n;
    while (cin>>n>>k) {
        N = n;
        FOR(i,0,n) cin>>A[i];
        int ans = -1;
        FOR(i,0,n) ans = max(ans, f(i, k));
        cout << ans << '\n';
    }

    return 0;
}

/*
4 2
1 1 -1 1
14 3
-1 1 -1 -1 1 -1 -1 1 -1 -1 1 -1 -1 1
*/
