#include <bits/stdc++.h>
#define FOR(i,a,n) for (int i=a; i<n; i++)
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t, l, r, d;
    cin >> t;
    while (t--) {
        cin >> l >> r >> d;
        int ans = d;
        if (l <= ans) ans = r - r % d + d;
        cout << ans << '\n';
    }

    return 0;
}
