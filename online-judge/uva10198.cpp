// uva10198
// dp

#include <iostream>
using namespace std;

int dp[1005][1005]={0};
int n;

int main()
{
	dp[1][0] = 2;
	dp[2][0] = 5;
	dp[3][0] = 3, dp[3][1] = 1; //13
	dp[4][0] = 3, dp[4][1] = 3; //33
	for (int i=5; i<=1000; i++) {
        for (int j=0; j<1000; j++)
	       dp[i][j] = dp[i-1][j]+dp[i-2][j]+dp[i-3][j]+dp[i-1][j];
        for (int j=0; j<1000; j++) {
            dp[i][j+1] += dp[i][j]/10;
            dp[i][j] %= 10;
        }
    }
	while (cin>>n) {
	    int i=1000;
	    while (dp[n][i]==0 && i >= 0) i--;
	    while (i >= 0) cout << dp[n][i--];
	    cout<<'\n';
    }
	return 0;
}
