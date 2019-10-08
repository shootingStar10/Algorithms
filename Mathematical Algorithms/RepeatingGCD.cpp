/*
Given three  integers N, x and y, a number A is formed by repeating N x times and another number B is formed by
repeating N y times. You need to find the GCD(A,B).

Solution: GCD(f(n, x), f(n, y)) = f(n, GCD(x, y)).
*/

#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll gcd(ll a, ll b)
{
    if (a == 0) {
        return b;
    }

    return gcd(b%a, a);
}

void solve(ll n, ll x, ll y)
{
    ll t = gcd(x, y);

    for (ll i = 0; i < t; i++) {
        cout<<n;
    }

    cout<<endl;
}

int main()
{
    int t;
    ll n, x, y;

    cin>>t;

    while (t--) {
        cin>>n>>x>>y;
        solve(n, x, y);
    }

    return 0;
}
