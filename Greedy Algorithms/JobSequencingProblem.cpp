/*
Given an array of jobs where every job has a deadline and associated profit if the job is finished before the deadline.
It is also given that every job takes single unit of time, so the minimum possible deadline for any job is 1.
How to maximize total profit if only one job can be scheduled at a time.
*/

#include <bits/stdc++.h>

using namespace std;

struct Job
{
    int id, deadline, profit;
};

bool compare(Job x, Job y)
{
    return x.profit > y.profit;
}

void solve(Job a[], int n)
{
    sort(a, a+n, compare);
    int t = 0, sum = 0;
    bool slot[n];

    for (int i = 0; i < n; i++) {
        slot[i] = false;
    }

    for (int i = 0; i < n; i++) {
        for (int j = min(n, a[i].deadline)-1; j >= 0; j--) {
            if (slot[j] == false) {
                t++;
                sum += a[i].profit;
                slot[j] = true;
                break;
            }
        }
    }

    cout<<t<<" "<<sum<<endl;
}

int main()
{
    int t, n, x, y, z;

    cin>>t;

    while (t--) {
        cin>>n;
        Job a[n];

        for (int i = 0; i < n; i++) {
            cin>>x>>y>>z;
            a[i].id = x;
            a[i].deadline = y;
            a[i].profit = z;
        }

        solve(a, n);
    }

    return 0;
}

/*
Time complexity: O(N^2)
Space complexity: O(N)
*/
