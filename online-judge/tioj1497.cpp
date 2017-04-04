// tioj1497
// suffix array
#include <bits/stdc++.h>
#define int long long
#define MS(s,v) memset(s,v,sizeof(s))
#define _FOR(i,start,end,step) for (int i=start; i!=end; i+=step)
#define FOR(i,start,end) for (int i=start; i<end; ++i)
using namespace std;
const long long INF = 0x3f3f3f3f3f3f3f3fLL;
const int N = 200002;
int sa[N]; // suffix array: id of i-th small suffix
int la[N]; // LCP array: LCP of i-th and i-1-th small suffix
int ra[N]; // rank: rank of s[i:n]
void makesa(const char* s, int n) {
    int tp[N];
    iota(sa, sa+n, 0);
    copy(s, s+n, ra); // use ascii as rank
    fill(ra+n, ra+2*n, -1);

    for (int k=1; k<n; k*=2) {
        sort(sa, sa+n, [k](int i,int j) {
            if (ra[i] != ra[j])
                return ra[i] < ra[j];
            else
                return ra[i+k] < ra[j+k];
        });

        tp[sa[0]]=0;
        int t=0;
        FOR(i,1,n) {
            if (ra[sa[i]] != ra[sa[i-1]]
                || ra[sa[i]+k] != ra[sa[i-1]+k])
                // not equal to last one
                ++t;
            tp[sa[i]] = t;
        }
        copy(tp, tp+n, ra);

        // all different
        if (t == n) break;
    }
}
void makela(const char* s, int n) {
    int k=0;
    for (int i=0; i<n; i++) {
        if (ra[i]>0) {
            while (s[i+k] == s[sa[ra[i]-1]+k]) k++;
        }
        la[ra[i]]=k;
        k = max(k-1, 0LL);
    }
}
main() {
#ifdef soytw
    freopen("in.txt","r",stdin);
#else
    ios::sync_with_stdio(0);
    cin.tie(0);
#endif
    string s;
    while (getline(cin,s)) {
        makesa(s.c_str(), s.size());
        FOR(i,0,s.size()) cout<<sa[i]<<'\n';
    }
#ifdef soytw
    freopen("con","r",stdin);
    system("pause");
#endif
    return 0;
}
