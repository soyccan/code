#include <bits/stdc++.h>
#define int long long
#define MS(s,v) memset(s,v,sizeof(s))
#define FOR(i,end) for (int i=0; i<end; ++i)
#define FOR1(i,end) for (int i=1; i<=end; ++i)
using namespace std;
const long long INF = 0x3f3f3f3f3f3f3f3fLL;
int A[10000];
main() {
#ifdef soytw
    freopen("in.txt","r",stdin);
#else
    ios::sync_with_stdio(0);
    cin.tie(0);
#endif
    int n,k;
    while (cin>>k>>n) {
    	set<int> st;
        FOR1(i, n) cin>>A[i];
        FOR1(i, n) FOR1(j, n) if (i<j) st.insert((A[i]-A[j])*(A[i]-A[j]));
        int sum=0, i=0;
        for (int e : st) {
        	sum += e;
        	i++;
        	if (i>=2*k)  break;
        }
        cout << sum << '\n';
    }
#ifdef soytw
    freopen("con","r",stdin);
    system("pause");
#endif
    return 0;
}