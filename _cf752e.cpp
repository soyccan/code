// cf752e
// undone
#include <bits/stdc++.h>
#define int long long
#define MS(s,v) memset(s,v,sizeof(s))
#define FOR(i,st,en) for (int i=st; i<=en; ++i)
#define RFOR(i,st,en) for (int i=st; i>=en; --i)
using namespace std;
const int INF = 0x3f3f3f3f3f3f3f3fLL;
int arr[1000005];
bool check(int lb,int k,int n) {
    set<int> s;
    FOR(i,0,min(k,n)-1) s.insert(arr[i]);
    int mn=arr[k-1];
    while (mn<lb) {
        int a=*s.rbegin(); // biggest
        int b=*s.begin(); // smallest
        int h=a/2;
        if (h>b) {
            s.erase(s.begin());
            s.erase(--s.end());
            s.insert(h);
            s.insert(a-h);
            mn=h;
        } else {
            return 0;
        }
    }
    return 1;
}
main() {
#ifdef XD
    freopen("in.txt","r",stdin);
#else
    ios::sync_with_stdio(0);
    cin.tie(0);
#endif
    int n,k;
    while (cin>>n>>k) {
        FOR(i,0,n-1) cin>>arr[i];
        sort(arr,arr+n,greater<int>());
        int l=0, r=1e7+5, ans=-1;
        while (l<r) {
            int m=(l+r)/2;
            if (check(m,k,n)) { ans=m; break; }
            else l=m+1;
        }
        cout<<ans<<'\n';
    }
    return 0;
}
