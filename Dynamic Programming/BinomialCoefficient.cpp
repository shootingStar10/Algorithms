/*
Find nCr % M;
*/

#include <bits/stdc++.h>
#define M 1000000007

using namespace std;

long long dp[1005][1005];

long long solve(int n, int r)
{
    if (r == 0 || r == n || n == 1) {
        dp[n][r] = 1;
        return dp[n][r];
    }

    if (r == 1) {
        dp[n][r] = n;
        return dp[n][r];
    }

    if (r > n) {
        dp[n][r] = 0;
        return dp[n][r];
    }

    if (dp[n][r] != -1) {
        return dp[n][r];
    }

    dp[n][r] = solve(n-1, r) + solve(n-1, r-1);
    dp[n][r] %= M;

    return dp[n][r];
}

int main()
{
    int t, n, r;

    cin>>t;

    while (t--) {
        cin>>n>>r;

        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= r; j++) {
                dp[i][j] = -1;
            }
        }

        solve(n, r);
        cout<<dp[n][r]<<endl;
    }

    return 0;
}

/*
Time complexity: O(n*r)
Space complexity: O(n*r)
*/
