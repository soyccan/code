#include <bits/stdc++.h>
using namespace std;
int arr[1005][1005];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	double a,b,c,d;
	vector<double> v,tmp;
	memset(arr,0,sizeof arr);
	for (int i=1; i<=4; i*=2) {
		cin>>a>>b>>c>>d;
		if (a > c) swap(a,c);
		if (b > d) swap(b,d);
		v.push_back(a);
		v.push_back(b);
		v.push_back(c);
		v.push_back(d);
	}
	tmp=v;
	sort(tmp.begin(), tmp.end());
	for (int i=0; i<v.size(); i++) {
		mp[v[i]]=lower_bound(tmp.begin(), tmp.end(), v[i])-tmp.begin();
		rmp[mp[v[i]]]=v[i];
	}


		for (int j=a; j<c; j++)
			for (int k=b; k<d; k++)
				arr[j][k]+=i;
	int one=0, two=0, three=0;
	// for (int i=11; i>=1; i--) {
	// 	for (int j=1; j<=11; j++)
	// 		cout<<arr[j][i]<<' ';
	// 	cout<<endl;
	// }
	for (int i=1; i<=1001; i++)
		for (int j=1; j<=1001; j++)
			if (arr[i][j]==1||arr[i][j]==2||arr[i][j]==4)
				one++;
			else if (arr[i][j]==3||arr[i][j]==5||arr[i][j]==6)
				two++;
			else if (arr[i][j]==7)
				three++;
	cout<<three<<".00 "<<two<<".00 "<<one<<".00\n";
	return 0;
}