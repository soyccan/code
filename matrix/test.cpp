#include <bits/stdc++.h>
#include "matrix.h"
#define MS(s,v) memset(s,v,sizeof(s))
#define FOR(i,end) for (int i=0; i<end; ++i)
#define FOR1(i,end) for (int i=1; i<=end; ++i)
using namespace std;
main() {
	// test: 2 -1 0 -1 2 -1 0 -1 2
	// inverse: 0.75 0.5 0.25 0.5 1 0.5 0.25 0.5 0.75
	SquareMatrix<double> m(3);
	for (int i=0; i<3; i++)
		for (int j=0; j<3; j++)
			cin>>m[i][j];
	SquareMatrix<double> I = identity_matrix<double>(3);
	SquareMatrix<double> k = inverse(m);
	Matrix<double> a = augment(m, I);
	cout<<a<<endl;
	a._gauss();
	cout<<a<<endl;
	a._gauss_jordan();
	cout<<a<<endl;
	cout<<k<<endl;
	cout<<m*k<<endl;

#ifdef soytw
    freopen("con","r",stdin);
    system("pause");
#endif
    return 0;
}
