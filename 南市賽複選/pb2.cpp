#include <bits/stdc++.h>
using namespace std;
int N,M;
int arr[10000];
bool used[10000]={0};
vector<int> sol;
void bt() {
	for (int e:sol)cout<<e;
	cout<<'\n';
	if (sol.size() == N+1) {
		for (int e:sol)cout<<e;
		cout<<'\n';return;
	}
	for (int i=0; i<N; i++) {
		if (!used[i]) {
			used[i]=1;
			sol.push_back(arr[i]);
			bt();
			sol.pop_back();
			used[i]=0;
		}
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	// int a,b,c;
	cin>>N;
	for (int i=0; i<2*N; i++) cin>>arr[i];
	sort(arr,arr+N);
	if (N == 2) arr[2]=arr[3];
	bt();
	return 0;
}