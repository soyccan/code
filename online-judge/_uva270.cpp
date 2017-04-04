// uva270
// point and line
#include <bits/stdc++.h>
#define int long long
#define double long double
#define MS(s,v) memset(s,v,sizeof(s))
#define _FOR(i,start,end,step) for (int i=start; i!=end; i+=step)
#define FOR(i,start,end) for (int i=start; i<end; ++i)
using namespace std;
const long long INF = 0x3f3f3f3f3f3f3f3fLL;
typedef pair<double,double> pdd;
typedef pair<int,int> pii;
pii arr[1005];
map<pdd, int> cnt;
pdd line(int x1,int y1,int x2,int y2) {
    // y = mx + b
    if (x1 == x2) return make_pair(INF, INF);
    double m = (y1-y2) / (x1-x2);
    double b = y1 - m*x1;
    return make_pair(m, b);
}
main() {
#ifdef soytw
    freopen("in.txt","r",stdin);
#else
    ios::sync_with_stdio(0);
    cin.tie(0);
#endif
    int n,t; string s,s1;
    cin>>t;
    getchar();
    getchar();
    while (t--) {
        n=0;
        while (getline(cin,s) && s!="") {
            stringstream ss(s);
            ss>>arr[n].first>>arr[n].second;
            n++;
        }
        // FOR(i,0,n) cout<<arr[i].first<<' '<<arr[i].second<<endl;
        cnt.clear();
        FOR(i,0,n) FOR(j,i+1,n) {
            pdd ln = line(arr[i].first, arr[i].second, arr[j].first, arr[j].second);
            cnt[ln]++;
        }
        int mxcnt=-1;
        pdd mxln;
        for (auto e : cnt) {
            // cout<<e.first.first<<' '<<e.first.second<<':'<<e.second<<endl;;
            if (e.second > mxcnt) {
                mxcnt = e.second;
                mxln = e.first;
            }
        }
        int ans=0;
        FOR(i,0,n)
            if (arr[i].second == mxln.first*arr[i].first + mxln.second)
                ans++;
        cout<<ans<<"\n";
        if (t!=0) cout<<'\n';
    }
#ifdef soytw
    freopen("con","r",stdin);
    system("pause");
#endif
    return 0;
}
