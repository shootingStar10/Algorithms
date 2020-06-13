#include <bits/stdc++.h>

using namespace std;

int dp[1003][1003];
int pre[1003];

int optCost(int free[], int lo, int hi)
{
    if (lo > hi) {
        return 0;
    }

    if (lo == hi) {
        dp[lo][hi] = free[lo];
        return dp[lo][hi];
    }

    if (dp[lo][hi] != -1) {
        return dp[lo][hi];
    }

    int sum = pre[hi] - pre[lo-1];

    int minCost = INT_MAX;

    for (int i = lo; i <= hi; i++) {
        int cost = optCost(free, lo, i-1) + optCost(free, i+1, hi);

        if (cost < minCost) {
            minCost = cost;
        }
    }

    dp[lo][hi] = sum + minCost;

    return dp[lo][hi];
}

int main()
{
    int keys[] = {10, 12, 20};
    int free[] = {34, 8, 50};
    int n = 3;

    pre[0] = free[0];

    for (int i = 1; i < n; i++) {
        pre[i] = pre[i-1] + free[i];
    }

    memset(dp, -1, sizeof(dp));
    int cost = optCost(free, 0, n-1);

    cout<<cost<<endl;

    return 0;
}

/*

Problem: Given a sorted array keys[0.. n-1] of search keys and an array freq[0.. n-1] of frequency
counts, where freq[i] is the number of searches to keys[i]. Construct a binary search tree of all keys
such that the total cost of all the searches is as small as possible.

Let us first define the cost of a BST. The cost of a BST node is level of that node multiplied by
its frequency. Level of root is 1.


Time Complexity: O(n^3) after pre-computation
Space Complexity: O(n^2)

*/
