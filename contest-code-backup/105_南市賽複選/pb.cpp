#include <bits/stdc++.h>
using namespace std;
int N,M;
int arr[1000];
bool equal(int a,int b,int c) {
	return a==b&&b==c;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>N;
	for (int i=0; i<2*N; i++) cin>>arr[i];
	sort(arr,arr+2*N);
	if (N==1) {
		cout<<arr[0]<<arr[1]<<'\n';
		cout<<arr[1]<<arr[0]<<'\n';
	} else if (N==2) {
		arr[2]=arr[3];
		if (equal(arr[0]%3, arr[1]%3, arr[2]%3)||
		    equal((arr[0]-1)/3, (arr[1]-1)/3, (arr[2]-1)/3)||
		    equal(arr[0]%4, arr[1]%4, arr[2]%4)) {
			cout<<arr[0]<<arr[1]<<arr[2]<<'\n';
			cout<<arr[1]<<arr[0]<<arr[2]<<'\n';
			cout<<arr[1]<<arr[2]<<arr[0]<<'\n';
			cout<<arr[2]<<arr[1]<<arr[0]<<'\n';
		} else {
			cout<<arr[0]<<arr[1]<<arr[2]<<'\n';
			cout<<arr[2]<<arr[1]<<arr[0]<<'\n';
		}
	}
	return 0;
}