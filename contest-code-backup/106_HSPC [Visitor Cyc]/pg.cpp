#include<bits/stdc++.h>
#define double long double
#define pii pair<double,double> 
using namespace std;
vector<pii> A;
vector<pii> S,B;
const double INF = 1e8;
int sgn(double x) {
	if (x < -1e-10) return -1;
	else if (x > 1e-10) return 1;
	else return 0;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t,n;
	double x1,y1,x2,y2;
	cin>>t;
	while (t--) {
		A.clear(); S.clear(); B.clear();
		cin>>n;
		for (int i=0; i<n; i++) {
			cin>>x1>>y1>>x2>>y2;
//			double a=atan2(y1,x1), b=atan2(y1,x2), c=atan2(y2,x1), d=atan2(y2,x2);
			double a=y1/x1, b=y1/x2, c=y2/x1, d=y2/x2;
			if(x1==0)
			{
			    a = INF * sgn(y1);
			    c = INF * sgn(y2);
			}
			if (x2==0) {
				b = INF * sgn(y1);
				d = INF * sgn(y2);
			}
			double mn=min({a,b,c,d}), mx=max({a,b,c,d});
			A.push_back(make_pair(mn, mx));
			if(x1 != 0 && x2 != 0)
			    B.push_back(make_pair(mn,mx));
		}
		sort(A.begin(), A.end(), [](pii a,pii b) { return a.first < b.first; });
		sort(B.begin(), B.end(), [](pii a,pii b) { return a.first < b.first; });
		
//		for (pii e : A) cout<<e.first<<' '<<e.second<<endl;
//		cout<<endl;
//		for (pii e : B) cout<<e.first<<' '<<e.second<<endl;
//		cout<<endl;
		
		int ans;
		S.clear();
		S.push_back(A[0]);
		for (int i=1; i<A.size(); i++) {
			if (sgn(A[i].first - S.back().second) <= 0)
				S.back().first = A[i].first,
				S.back().second = min(A[i].second, S.back().second);
			else
				S.push_back(A[i]);
		}
		ans = S.size();
//		cout << "K " << ans << " ";

		S.clear();
		if(!B.empty())
		{
			S.push_back(B[0]);
			for (int i=1; i<B.size(); i++) {
				if (sgn(B[i].first - S.back().second) <= 0)
					S.back().first = B[i].first,
					S.back().second = min(B[i].second, S.back().second);
				else
					S.push_back(B[i]);
			}
		}
		ans = min(ans, (int)S.size()+1);

//		cout<<"Q"<<ans<<'\n';
		cout<<ans<<'\n';
	}
	return 0;
}
/*
3
4
0 -20 10 -10
10 -9 20 10
5 10 10 20
0 20 4 30
5
0 -20 10 -10
10 -10 20 10
5 10 10 20
4 20 5 21 
0 21 50 25
4
0 1 2 3
3 1 5 6
2 5 4 10
0 -10 1 -8
*/

