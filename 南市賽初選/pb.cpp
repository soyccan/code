#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
int arr[10000005];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,k;
	cin>>n>>k;
	for (int i=0; i<n; i++) cin>>arr[i];
	sort(arr,arr+n);
	cout<<arr[n-2]<<endl;
	return 0;
}