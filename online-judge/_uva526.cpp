#include <bits/stdc++.h>
using namespace std;
int dp[100][100];
string A,B;
int cnt;
inline int DP(int i,int j) {
    if (dp[i][j]==-1) {
        if (i==0 || j==0)
            dp[i][j]=i+j;
        else if (A[i-1]==B[j-1])
            dp[i][j]=DP(i-1,j-1);
        else {
            dp[i][j]=1e9;
            // insert
            dp[i][j]=min(dp[i][j],DP(i,j-1)+1);
            // delete
            dp[i][j]=min(dp[i][j],DP(i-1,j)+1);
            // replace
            dp[i][j]=min(dp[i][j],DP(i-1,j-1)+1);
        }
//        cout<<"i:"<<i<<" j:"<<j<<" dp:"<<dp[i][j]<<endl;
    }
    return dp[i][j];
}
inline void print(int i,int j) {
//    cout<<"i:"<<i<<" j:"<<j<<endl;
    if (i<0 || j<0)
        return;
    else if (i==0) {
        print(i,j-1);
        cout<<cnt++<<" Insert "<<j<<" "<<B[j]<<'\n';
    }
    else if (j==0) {
        print(i-1,j);
        cout<<cnt++<<" Delete "<<i<<'\n';
    }
    else if (A[i-1]==B[j-1])
        print(i-1,j-1);
    else {
        // insert
        if (dp[i][j]==dp[i][j-1]+1) {
            cout<<cnt++<<" Insert "<<i<<'\n';
            print(i,j-1);
        }
        // delete
        else if (dp[i][j]==dp[i-1][j]+1) {
            cout<<cnt++<<" Delete "<<i<<'\n';
            print(i-1,j);
        }
        // replace
        else if (dp[i][j]==dp[i-1][j-1]+1) {
            cout<<cnt++<<" Replace "<<i<<','<<B[j-1]<<'\n';
            print(i-1,j-1);
        }
    }
}
void debug() {
    for (int i=0; i<=A.size(); i++) {
        for (int j=0; j<=B.size(); j++)
            cout<<dp[i][j]<<' ';
        cout<<endl;
    }
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("in.txt","r",stdin);
	while (getline(cin,A)) {
        getline(cin,B);
        cnt=1;
        memset(dp,-1,sizeof dp);
        cout<<DP(A.size(),B.size())<<'\n';
        debug();
        print(A.size(),B.size());
        cout<<'\n';
	}
	return 0;
}
