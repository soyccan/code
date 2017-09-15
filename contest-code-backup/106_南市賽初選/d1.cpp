#include <bits/stdc++.h>
#define int long long
#define MS(s,v) memset(s,v,sizeof(s))
#define FOR(i,end) for (int i=0; i<end; ++i)
#define FOR1(i,end) for (int i=1; i<=end; ++i)
using namespace std;
const long long INF = 0x3f3f3f3f3f3f3f3fLL;
int A[100];

main() {
#ifdef soytw
    freopen("in.txt","r",stdin);
#else
    ios::sync_with_stdio(0);
    cin.tie(0);
#endif
    int n;
    while (cin>>n) {
        A[1]=1, A[2]=2;
        int sum=3;
        for (int i=3; i<=n; i++) {
        	A[i] = A[i-1] + i - 2;
        	cout << A[i]<<endl;
        	sum+=A[i];
        }
        cout <<sum;
    }
#ifdef soytw
    freopen("con","r",stdin);
    system("pause");
#endif
    return 0;
}