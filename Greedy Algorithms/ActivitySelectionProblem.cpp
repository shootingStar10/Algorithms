#include <bits/stdc++.h>

using namespace std;

struct activity
{
    int start;
    int finish;
};

bool compare(const pair <activity, int> &x, const pair <activity, int> &y)
{
    return (x.first.finish < y.first.finish);
}

void solve(vector <pair <activity, int> > &v, int n)
{
    sort(v.begin(), v.end(), compare);

    cout<<v[0].second<<" ";
    int j = 0;

    for (int i = 1; i < n; i++) {
        if (v[i].first.start >= v[j].first.finish) {
            cout<<v[i].second<<" ";
            j = i;
        }
    }

    cout<<endl;
}

int main()
{
    int t, n;

    cin>>t;

    while (t--) {
        cin>>n;
        vector <pair <activity, int> > v;
        int s[n], f[n];

        for (int i = 0; i < n; i++) {
            cin>>s[i];
        }

        for (int i = 0; i < n; i++) {
            cin>>f[i];
        }

        for (int i = 0; i < n; i++) {
            activity a;
            a.start = s[i];
            a.finish = f[i];
            v.push_back(make_pair(a, i+1));
        }

        solve(v, n);
    }

    return 0;
}
