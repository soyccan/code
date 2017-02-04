#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
int arr[100000005];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int N,k;
	cin>>N;
	for (int i=0; i<N; i++) cin>>arr[i];
	int ans = -1;
	int first=-1, second=-2;
		for (int j=0; j<N; j++) {
			if (arr[j] > first) {
				second = first;
				first = arr[j];
			}
			else if (arr[j] < first && arr[j] > second) second = arr[j];
		}
		cout<<first<<' '<<second;
	return 0;
}
