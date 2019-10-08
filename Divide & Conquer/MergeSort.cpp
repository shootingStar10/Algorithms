#include <bits/stdc++.h>

using namespace std;

void _merge(int a[], int lo, int mid, int hi)
{
    int n1 = mid-lo+1;
    int n2 = hi-mid;
    int l[n1], r[n2];

    for (int i = 0; i < n1; i++) {
        l[i] = a[lo+i];
    }

    for (int i = 0; i < n2; i++) {
        r[i] = a[mid+1+i];
    }

    int i = 0, j = 0, k = lo;

    while (i < n1 && j < n2) {
        if (l[i] <= r[j]) {
            a[k++] = l[i];
            i++;
        } else {
            a[k++] = r[j];
            j++;
        }
    }

    while (i < n1) {
        a[k++] = l[i];
        i++;
    }

    while (j < n2) {
        a[k++] = r[j];
        j++;
    }
}

void merge_sort(int a[], int lo, int hi)
{
    if (lo < hi) {
        int mid = (lo+hi) / 2;

        merge_sort(a, lo, mid);
        merge_sort(a, mid+1, hi);
        _merge(a, lo, mid, hi);
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

    merge_sort(a, 0, n-1);

    for (int i = 0; i < n; i++) {
        cout<<a[i]<<" ";
    }

    cout<<endl;

    return 0;
}

/*
Time complexity: O(N*logN)
*/
