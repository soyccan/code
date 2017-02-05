#include <bits/stdc++.h>
#define int long long
#define MS(s,v) memset(s,v,sizeof(s))
#define _FOR(i,start,end,step) for (int i=start; i!=end; i+=step)
#define FOR(i,start,end) for (int i=start; i<end; ++i)
using namespace std;
const long long INF = 0x3f3f3f3f3f3f3f3fLL;

struct Mat {
	int a[20][20], r, c, m;
	Mat() {
		FOR(i,0,r) FOR(j,0,c) a[i][j]=0;
	}
	Mat operator*(const Mat& x) {
		Mat y;
		FOR(i,0,r) FOR(j,0,x.c) FOR(k,0,c)
			y.a[i][j] += (a[i][k] + x.a[k][j]) % m;
		return y;
	}
	Mat operator%(int m) {
		FOR(i,0,r) FOR(j,0,c) a[i][j]%=c;
	}
	Mat operator^(int e) {
		Mat y;
		FOR(i,0,max(r,c)) a[i][i]=1;
		while (e) {
			if (e&1) y = y*(*this)%m;
			*this = (*this)*(*this)%m;
			e/=2;
		}
		return y;
	}
} A, B;

void print(int d) {
	FOR(i,1,d+1) {
		FOR(j,1,d+1)
			cout<<A[i][j]<<' ';
		cout<<endl;
	}
	FOR(i,1,d+1) {
		FOR(j,1,d+1)
			cout<<B[i][j]<<' ';
		cout<<endl;
	}
	cout<<endl;
}
Mat pow(Mat a, int e, int r, int m) { // r==c
	Mat b;
	FOR(i,0,r) FOR(j,0,r)
		if (i==j) b[i][j]=1;
		else b[i][j]=0;
	while (e) {
		if (e&1) b=mul(b,a,r,r,r,m);
		a = mul(a,a,r,r,r,m);
		e /= 2;
	}
	return b;
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
        FOR(i,1,d+1) cin>>A[1][i];
        FOR(i,1,d+1) A[i+1][i]=1;
        _FOR(i,d,0,-1) cin>>B[i][1];
        print(d);
    }
#ifdef soytw
    freopen("con","r",stdin);
    system("pause");
#endif
    return 0;
}
