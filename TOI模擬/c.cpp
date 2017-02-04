#include <bits/stdc++.h>
#define int long long
#define MS(s,v) memset(s,v,sizeof(s))
#define _FOR(i,start,end,step) for (int i=start; i!=end; i+=step)
#define FOR(i,start,end) for (int i=start; i<end; ++i)
using namespace std;
const long long INF = 0x3f3f3f3f3f3f3f3fLL;
// int check(string S,string s) {
//  int i=0, j=0, cnt=0;
//  while (i<S.size() && j<s.size()) {
//      if (S[i]==s[j]) j++;
//      else j=0;
//      i++;
//      if (j==s.size()) cnt++, j=0;
//  }
//  return cnt;
// }
main() {
#ifndef soytw
    ios::sync_with_stdio(0);
    cin.tie(0);
#endif
    string s; int k;
    while (cin>>s>>k) {
        set<string> S;
        int mxln=0;
        FOR(l,0,s.size()) FOR(r,l,s.size()) {
            string t=s.substr(l,r-l+1);
            int cnt=0;
            FOR(j,0,s.size())
                if (s.find(t,j)==j)
                    cnt++;
            // cout<<';'<<t<<cnt<<endl;
            if (cnt==k) {
                if (t.size()>mxln) {
                    mxln=t.size();
                    S.clear();
                    S.insert(t);
                } else if (t.size()==mxln) {
                    S.insert(t);
                }
            }
        }
        for (string t : S) cout<<t<<'\n';
    }
    return 0;
}
