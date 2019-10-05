/*
 Bell(n) =  Sigma(k = 0 to n) S(n, k)
 where S(n+1, k) = k * S(n, k) + S(n, k-1)
*/

#include <bits/stdc++.h>

using namespace std;

int solve(int n)
{
    int dp[n+1][n+1];

    dp[1][1] = 1;

    for (int i = 2; i <= n; i++) {
        dp[i][1] = dp[i-1][i-1];

        for (int j = 2; j <= i; j++) {
            dp[i][j] = dp[i-1][j-1] + dp[i][j-1];
        }
    }

    return dp[n][n];
}

int main()
{
    int t, n;

    cin>>t;

    while (t--) {
        cin>>n;
        cout<<solve(n)<<endl;
    }

    return 0;
}
