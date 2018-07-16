// DP
// brute force to check answer
// given a number N, count ways to sum up N (different order count once)
#include <bits/stdc++.h>
using namespace std;

const size_t MAXN = 100;
long long dp[MAXN][MAXN];
// dp[i][j]: ways to sum up i with numbers not greater than j
long long ans;
vector<int> sol;
void dfs(int sum,int t) {
    if (sum == t) {
        ans++;
        return ;
    }
    if (sum > t) return;
    int i = 1;
    if (sol.size()) i=sol.back();
    for (; sum+i<=t; i++) {
        sol.push_back(i);
        dfs(sum+i, t);
        sol.pop_back();
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    memset(dp, 0, sizeof dp);
    dp[0][0] = dp[1][1] = 1;
    for (int i=1; i<MAXN; i++)
        for (int j=1; j<MAXN; j++)
            if (j <= i)
                dp[i][j] = dp[i][j-1] + dp[i-j][min(i-j, j)];

    // for (int i=0; i<=MAXN; i++) {
    //  for (int j=0; j<=MAXN; j++)
    //      cout << setw(3) << dp[i][j];
    //  cout << endl;
    // }


    for (int n=1; n<MAXN; n++) {
        ans=0;
        sol.clear();
        dfs(0, n);

        assert(ans == dp[n][n]);

        cout << n << ' ' << ans << ' ' << dp[n][n] << endl;
    }
    system("pause");
    return 0;
}

