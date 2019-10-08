#include <bits/stdc++.h>

using namespace std;

int _partition(int a[], int lo, int hi)
{
    int i = lo-1;
    int pivot = a[hi];

    for (int j = lo; j <= hi-1; j++) {
        if (a[j] < pivot) {
            i++;
            swap(a[i], a[j]);
        }
    }

    swap(a[i+1], a[hi]);
    return i+1;
}

void quick_sort(int a[], int lo, int hi)
{
    if (lo < hi) {
        int pivot = _partition(a, lo, hi);
        quick_sort(a, lo, pivot-1);
        quick_sort(a, pivot+1, hi);
    }
}

int main()
{
    int n;

    cin>>n;
    int a[n];

    for (int i = 0; i < n; i++) {
        cin>>a[i];
    }

    quick_sort(a, 0, n-1);

    for (int i = 0; i < n; i++) {
        cout<<a[i]<<" ";
    }

    cout<<endl;

    return 0;
}

/*
Time complexity: O(N*logN)
*/
