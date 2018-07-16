// uva11475
// KMP
#include <bits/stdc++.h>
#define MS(s,v) memset(s,v,sizeof(s))
#define _FOR(i,start,end,step) for (int i=start; i!=end; i+=step)
#define FOR(i,start,end) for (int i=start; i<end; ++i)
using namespace std;
int fail[100005];
char s[100005];
char rs[100005];
bool ok(string s,int p,int q) {
    for (int i=p,j=q; j<s.size(); i--,j++)
        if (s[i]!=s[j])
            return 0;
    return 1;
}
void solve_tle(string s,int n) {
    for (int i=n/2; i<n; i++) {
        if (ok(s,i-1,i)) {
            FOR(j,0,i) cout<<s[j];
            _FOR(j,i-1,-1,-1) cout<<s[j];
            cout<<'\n';
            break;
        }
        if (ok(s,i,i)) {
            FOR(j,0,i) cout<<s[j];
            _FOR(j,i,-1,-1) cout<<s[j];
            cout<<'\n';
            break;
        }
    }
}
main() {
    while (cin>>s) {
        int n=strlen(s);
        strcpy(rs,s);
        reverse(rs, rs+n);
        int p=-1;
        MS(fail,-1);
        FOR(i,1,n) {
            while (p!=-1 && rs[p+1]!=rs[i]) p=fail[p];
            if (rs[p+1]==rs[i]) fail[i]=++p;
        }
        p=-1;
        FOR(i,0,n) {
            while (p!=-1 && rs[p+1]!=s[i]) p=fail[p];
            if (rs[p+1]==s[i]) ++p;
        }
        cout<<s<<rs+p+1<<'\n';
    }
    return 0;
}
