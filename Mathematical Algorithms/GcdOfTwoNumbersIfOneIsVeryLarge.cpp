/*
Given two numbers a and b such that (0 <= a <= 10^12 and b <= b < 10^250). Find the GCD of two given numbers.
*/

#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll reduce(string s, ll a)
{
    ll n = 0;

    for (int i = 0; i < s.length(); i++) {
        n = (n*10 + (s[i]-'0'))%a;
    }

    return n;
}

ll gcd(ll a, ll b)
{
    if (a == 0) {
        return b;
    }

    return gcd(b%a, a);
}

int main()
{
    ll a = 978;
    string s = "89798763754892653453379597352537489494736";

    ll b = reduce(s, a);
    cout<<gcd(a, b)<<endl;

    return 0;
}
