#include <bits/stdc++.h>
using namespace std;
int N,M;
vector<int> arr[4];
int used[4][20];
inline bool wrong(int a,int b,int v) {
	for (int i=0; i<4; i++)
		if (i!=a && i!=b && used[i][v]>1)
			return 1;
	return 0;
}
inline bool solve() {
	while (arr[0].size()&&arr[1].size()&&arr[2].size()&&arr[3].size()) {
		bool f=0;
		for (int i=0; i<4; i++) {
			for (int j=i+1; j<4; j++) {
				if (arr[i].size()>=2 && arr[j].size()>=2 && arr[i][arr[i].size()-1] == arr[j][arr[j].size()-1]) {
		for (int i=0; i<4; i++) {
			for (int j=i+1; j<4; j++) {
				if (arr[i].size() && arr[j].size() && arr[i].back() == arr[j].back()) {
					if (wrong(i,j,arr[i].back())) continue;
					arr[i].pop_back();
					arr[j].pop_back();
					f=1;
				}
			}
		}
		if (!f) return false;
	}
	return true;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int x;
	while (cin>>x) {
		memset(used,0,sizeof used);
		arr[0].clear();
		arr[1].clear();
		arr[2].clear();
		arr[3].clear();
		arr[0].push_back(x);
		used[0][x]++;
		for (int i=1; i<13; i++) { cin>>x; used[0][x]++; arr[0].push_back(x); }
		for (int i=0; i<13; i++) { cin>>x; used[1][x]++; arr[1].push_back(x); }
		for (int i=0; i<13; i++) { cin>>x; used[2][x]++; arr[2].push_back(x); }
		for (int i=0; i<13; i++) { cin>>x; used[3][x]++; arr[3].push_back(x); }
		if (solve()) cout<<"YES\n";
		else cout<<"NO\n";
	}
	return 0;
}