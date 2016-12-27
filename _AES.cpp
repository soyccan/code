#include <bits/stdc++.h>
#define int long long
#define MS(a,v) memset(a,v,sizeof a)
#define FOR(i,l,r) for (int i=l; i<=r; i++)
using namespace std;
main() {
    string s;
    int K[5][5];
    int D[5][5];
    FOR(i,0,3) FOR(j,0,3) cin>>K[i][j];
    cin>>s;
    size_t p=0;
    while (p<s.size()) {
        // initial
        FOR(i,0,3) FOR(j,0,3)
            if (p<s.size()) D[i][j]=s[p++];
            else D[i][j]='\0';

        // add round key
        // FOR(i,0,3) FOR(j,0,3) D[i][j]^=K[i][j];
        
        // shift rows
        FOR(i,0,3) FOR(j,0,3-i) swap(D[i][j],D[i][j+i]);
        
        FOR(i,0,3) {
            FOR(j,0,3) cout<<(char)D[i][j]<<' ';
            cout<<endl;
        }
        cout<<endl;
    }
    return 0;
}
