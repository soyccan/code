#include "matrix.h"
#include <bits/stdc++.h>
using namespace std;
int main() {
	Matrix<double> a(3,3);
	for (int i=0; i<3; i++)
		for (int j=0; j<3; j++)
			cin>>a[i][j];
	cout<<a.determinant()<<endl;
	system("pause");
	return 0;
}
