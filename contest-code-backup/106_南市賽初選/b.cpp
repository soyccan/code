#include <bits/stdc++.h>
#define int long long
#define MS(s,v) memset(s,v,sizeof(s))
#define FOR(i,end) for (int i=0; i<end; ++i)
#define FOR1(i,end) for (int i=1; i<=end; ++i)
using namespace std;
const long long INF = 0x3f3f3f3f3f3f3f3fLL;
int A[100005], P[100005];
main() {
#ifdef soytw
    freopen("in.txt","r",stdin);
#else
    ios::sync_with_stdio(0);
    cin.tie(0);
#endif
    int n, k;
    while (cin>>n>>k) {
        FOR1(i, n) cin>>A[i];
        P[0] = 0;
        FOR1(i, n) P[i] = P[i-1] + A[i];
        vector<int> v;
        FOR1(i, n) FOR(j, i) v.push_back(P[i]-P[j]);
        sort(v.rbegin(), v.rend());
        cout << v[k-1] << '\n';
    }
#ifdef soytw
    freopen("con","r",stdin);
    system("pause");
#endif
    return 0;
}