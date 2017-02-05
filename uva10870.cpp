// uva10870
// fast matrix exponentation
#include <bits/stdc++.h>
#define int long long
#define MS(s,v) memset(s,v,sizeof(s))
#define _FOR(i,start,end,step) for (int i=start; i!=end; i+=step)
#define FOR(i,start,end) for (int i=start; i<end; ++i)
using namespace std;
const long long INF = 0x3f3f3f3f3f3f3f3fLL;

struct Mat {
    int a[100][100], r, c, m;
    Mat() {
        MS(a,0);
        r = c = 0;
        m = 1;
    }
    Mat& operator=(const Mat& x) {
        memcpy(a, x.a, sizeof a);
        r=x.r, c=x.c, m=x.m;
        return *this;
    }
} A, B;
Mat unit_mat(int d, int m) {
    Mat x;
    x.r = x.c = d;
    x.m = m;
    FOR(i,0,d) x.a[i][i]=1;
    return x;
}
ostream& operator<<(ostream& os, const Mat& x) {
    FOR(i,0,x.r) {
        FOR(j,0,x.c) os<<x.a[i][j]<<' ';
        os<<endl;
    }
    return os;
}
Mat operator*(const Mat& x, const Mat& y) {
    Mat z;
    if (x.c != y.r) { cout<<"ERR\n"; return z; }
    z.m=x.m, z.r=x.r, z.c=y.c;
    // cout<<x.r<<x.c<<y.r<<y.c<<endl;
    FOR(i,0,x.r) FOR(j,0,y.c) FOR(k,0,x.c) {
        z.a[i][j] += x.a[i][k] * y.a[k][j];
        z.a[i][j] %= x.m;
    }
    return z;
}
Mat operator%(Mat x, int m) {
    FOR(i,0,x.r) FOR(j,0,x.c) x.a[i][j]%=m;
    return x;
}
Mat operator^(Mat x, int e) {
    Mat y = unit_mat(x.r, x.m);
    while (e) {
        // cout<<'e'<<e<<endl<<x<<y<<endl;
        if (e & 1) y = y * x % x.m;
        x = x * x % x.m;
        e >>= 1;
    }
    return y;
}

main() {
#ifdef soytw
    freopen("in.txt","r",stdin);
#else
    ios::sync_with_stdio(0);
    cin.tie(0);
#endif
    int n,d,m;
    while (cin>>d>>n>>m && d && n && m) {
        A = B = Mat();
        A.r = A.c = B.r = d;
        B.c = 1;
        A.m = B.m = m;
        FOR(i,0,d) cin>>A.a[0][i];
        FOR(i,0,d) A.a[i+1][i]=1;
        for (int i=d-1; i>=0; i--) cin>>B.a[i][0];
        A=A%m, B=B%m;
        cout<<((A^(n-1))*B).a[d-1][0]%m<<'\n';
    }
#ifdef soytw
    freopen("con","r",stdin);
    system("pause");
#endif
    return 0;
}
