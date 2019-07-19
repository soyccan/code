#include <bits/stdc++.h>
#define M_PI 3.14159265359
#define FOR(i, a, n) for (int i = a; i < n; i++)
using namespace std;

int main() {
#ifdef LOCAL
    freopen("in.txt","r",stdin);
#else
    ios::sync_with_stdio(0);
    cin.tie(0);
#endif
    int n,r;
    while (cin>>n>>r) {
        cout << fixed << setprecision(7) << (r * sin(M_PI / n))/(1 - sin(M_PI / n)) << '\n';
    }
    return 0;
}
