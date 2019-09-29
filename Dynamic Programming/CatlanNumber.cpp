/*
Sequence 1, 1, 2, 5, 14, 42, 132, 429 .... are called catlan numbers.
Cn = (2*n)! / (n+1)! * n! or C(n) = sigma{i=0 to n-1}(C(i) * C(n-1-i))
*/

#include <bits/stdc++.h>

using namespace std;

long long dp[1000];

long long solve(long long n)
{
    if (n <= 1) {
        dp[n] = 1;
        return dp[n];
    }

    if (dp[n] != -1) {
        return dp[n];
    }

    long long sum = 0;

    for (int i = 0; i < n; i++) {
        sum += solve(i)*solve(n-i-1);
    }

    dp[n] = sum;

    return dp[n];
}

int main()
{
    long long t, n;

    cin>>t;

    while (t--) {
        cin>>n;

        for (int i = 0; i <= n; i++) {
            dp[i] = -1;
        }

        solve(n);
        cout<<dp[n]<<endl;
    }

    return 0;
}

/*
Time Complexity: O(N^2)
Space Complexity: O(N)
*/
