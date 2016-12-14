// uva1411
// km
#include <bits/stdc++.h>
#define int long long
#define double long double
#define MS(a,v) memset(a,v,sizeof a)
#define FOR(i,l,r) for (int i=l; i<=r; ++i)
#define RFOR(i,l,r) for (int i=l; i>=r; --i)
using namespace std;
const double INF = 1e10;
const double EPS = 1e-10;
typedef complex<double> Point;
double G[105][105],lx[105],ly[105];
int match[105];
bool vx[105],vy[105];
Point co[105],ap[105];
int sgn(double x) {
    if (x<-EPS) return -1;
    else if (x>EPS) return 1;
    else return 0;
}
bool dfs(int x,int n) {
    vx[x]=1;
    FOR(y,1,n) {
        if (!vy[y] && sgn(lx[x]+ly[y]-G[x][y])==0) {
            vy[y]=1;
            if (match[y]==-1 || dfs(match[y],n)) {
                match[y]=x;
                return 1;
            }
        }
    }
    return 0;
}
main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,tc=0;
    while (cin>>n) {
        MS(G,0);
        FOR(i,1,n) {
            double x,y;
            cin>>x>>y;
            co[i]=Point(x,y);
        }
        FOR(i,1,n) {
            double x,y;
            cin>>x>>y;
            ap[i]=Point(x,y);
        }
        FOR(i,1,n)
            FOR(j,1,n)
                G[i][j]=-abs(co[j]-ap[i]);
        MS(match,-1); MS(ly,0);
        FOR(i,1,n) lx[i]=-INF;
        FOR(i,1,n) FOR(j,1,n) lx[i]=max(lx[i],G[i][j]);
        FOR(i,1,n) {
            for (;;) {
                MS(vx,0); MS(vy,0);
                if (dfs(i,n)) break;
                double d=INF;
                FOR(x,1,n)
                    FOR(y,1,n)
                        if (vx[x] && !vy[y])
                            d=min(d,lx[x]+ly[y]-G[x][y]);
                if (d==INF) break;
                FOR(j,1,n) {
                    if (vx[j]) lx[j]-=d;
                    if (vy[j]) ly[j]+=d;
                }
            }
        }
        if (tc++) cout<<'\n';
        FOR(i,1,n) cout<<match[i]<<'\n';
    }
    return 0;
}
