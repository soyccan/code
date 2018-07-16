#include <bits/stdc++.h>
#define int long long
#define MS(s,v) memset(s,v,sizeof(s))
#define _FOR(i,start,end,step) for (int i=start; i!=end; i+=step)
#define FOR(i,start,end) for (int i=start; i<end; ++i)
using namespace std;
const long long INF = 0x3f3f3f3f3f3f3f3fLL;
const long long MOD = 1e9+7;
int A[1000005];
int hsh(int* a,int n) {
    int r = 0;
    FOR(i,1,n+1) r=(r*987+a[i])%MOD;
    return r;
}
void unhsh(int r,int* a,int n) {
    while (r) a[--n]=r%987, r/=987;
}
void turn(int k) {
    if (k==0) return;
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    turn(k-1);
    reverse(A+c, A+b+1);
}
main() {
#ifndef soytw
    ios::sync_with_stdio(0);
    cin.tie(0);
#endif
    int n,k;
    while (cin>>n) {
        FOR(i,1,n+1) cin>>A[i];
        cin>>k;
        turn(k);
        cout<<hsh(A,n)<<'\n';
    }
    return 0;
}
