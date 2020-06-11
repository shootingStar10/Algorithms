#include <bits/stdc++.h>

using namespace std;

void solve(int a[], int n, int i)
{
    if (i == n) {
        for (int k = 0; k < n; k++) {
            cout<<a[k]<<" ";
        }
        cout<<endl;

        return;
    }

    for (int j = i; j < n; j++) {
        swap(a[i], a[j]);
        solve(a, n, i+1);
        swap(a[i], a[j]);
    }
}

void printPermutation(int a[], int n)
{
    solve(a, n, 0);
}

int main()
{
    int a[] = {1, 2, 3, 4};
    int n = 4;

    printPermutation(a, n);

    return 0;
}
