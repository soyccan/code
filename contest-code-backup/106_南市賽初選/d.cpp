#include <bits/stdc++.h>
#define int long long
#define MS(s,v) memset(s,v,sizeof(s))
#define FOR(i,end) for (int i=0; i<end; ++i)
#define FOR1(i,end) for (int i=1; i<=end; ++i)
using namespace std;
const long long INF = 0x3f3f3f3f3f3f3f3fLL;

int A[1000002], P[1000002];
main() {
#ifdef soytw
    freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout);
#else
    ios::sync_with_stdio(0);
    cin.tie(0);
#endif
    A[1] = A[2] = 1; P[1] = 1;
    for (int i=3; i<=1000000; i++) A[i] = (A[i-1] + A[i-2]) % 1000000009;
    for (int i=2; i<=1000000; i++) P[i] = (P[i-1] + A[i]) % 1000000009;
    int n;
    while (cin>>n) {
    	if (n > 1000000) continue;
        cout << P[n] << '\n';
    }
#ifdef soytw
    freopen("con","r",stdin);
    system("pause");
#endif
    return 0;
}