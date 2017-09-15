#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;
int arr[1<<13][1<<13];
int cnt=1;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	ll n;
	cin>>n;
	for (int i=1; i<=1<<n; i+=1<<(n-1)) {
		for (int j=1; j<=1<<n; j++) {}
	}
	return 0;
}