/*
The numbers who are the multiples of 2, 3 & 5 are called ugly numbers. Given n, find nth ugly number.
*/

#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t, n;

    cin>>t;

    while (t--) {
        cin>>n;
        long long dp[n], n2 = 2, n3 = 3, n5 = 5, next_number;
        int i2 = 0, i3 = 0, i5 = 0;

        dp[0] = 1;

        for (int i = 1; i < n; i++) {
            next_number = min(n2, min(n3, n5));
            dp[i] = next_number;

            if (next_number == n2) {
                i2++;
                n2 = dp[i2]*2;
            }

            if (next_number == n3) {
                i3++;
                n3 = dp[i3]*3;
            }

            if (next_number == n5) {
                i5++;
                n5 = dp[i5]*5;
            }
        }

        cout<<dp[n-1]<<endl;
    }

    return 0;
}

/*
2
10
4

Time Complexity: O(n)
Space Complexity: O(n)
*/
