#include <iostream>
#define FOR(i,l,r) for (int i=l; i<r; i++)
using namespace std;
string A[1000];
main() {
//    ios::sync_with_stdio(false);
//    cin.tie(0);
//	freopen("in.txt", "r", stdin);
//	freopen("out.txt", "w", stdout);
	int l,h; string s;
	cin>>l>>h>>s;
	getchar();
	FOR(i,0,h) {
		getline(cin,A[i]);
	}
//	FOR(i,0,h) {
//		FOR(j,0,l*27) cout<<A[i][j];
//		cout<<endl;
//	}
	FOR(j,0,h) {
		FOR(i,0,s.size()) {
			int t;
			if ('a'<=s[i] && s[i]<='z') t=s[i]-'a';
			else if ('A'<=s[i] && s[i]<='Z') t=s[i]-'A';
			else t=26;
//			cout<<endl<<'t'<<t<<endl;
			FOR(k,l*t,l*(t+1)) {
				cout<<A[j][k];
//					cout<<j<<k<<endl;
			}
		}
		cout<<endl;
	}
	return 0;
}

