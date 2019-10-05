#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b)
{
    if (a == 0) {
        return b;
    }
    return gcd(b%a, a);
}

int main()
{
    int a = 90, b = 324;
    cout<<gcd(a, b)<<endl;

    return 0;
}

/*
Time Complexity: O(log(min(a, b)))
*/
