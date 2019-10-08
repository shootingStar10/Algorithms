#include <bits/stdc++.h>

using namespace std;

// Las Vegas randomized algorithm
int getRandomPivot(int x, int y)
{
    srand(time(NULL));
    return (x + rand() % (y-x+1));
}

// Implementation of randomized binary search
int solve(int a[], int k, int lo, int hi)
{
    if (lo <= hi) {
        int pivot = getRandomPivot(lo, hi);

        if (a[pivot] == k) {
            return pivot;
        } else if (a[pivot] < k) {
            return solve(a, k, pivot+1, hi);
        } else {
            return solve(a, k, lo, pivot-1);
        }
    }

    return -1;
}

int main()
{
    int n, k;

    cin>>n>>k;
    int a[n];

    for (int i = 0; i < n; i++) {
        cin>>a[i];
    }

    cout<<solve(a, k, 0, n-1)<<endl;

    return 0;
}

/*
Time complexity: O(logN)
*/
