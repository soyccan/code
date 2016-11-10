#include <bits/stdc++.h>
using namespace std;
int dp[100][100];
inline void DP(int i,int j) {
    if (dp[i][j]!=-1) return dp[i][j];
    // insert
    if (a[i]==b[j])
        dp[i][j]=min(DP(i,j),dp[i-1][j]+1);
    // delete
    return dp[i][j];
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	string a,b;
	while (getline(cin,a)) {
        getline(cin,b);
        DP(a.size(),b.size());
        print();
        cout<<dp[a.size()-1][b.size()-1];
	}
	return 0;
}
