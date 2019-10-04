/*
Every positive fraction can be represented as sum of unique unit fractions. A fraction is unit fraction if numerator
is 1 and denominator is a positive integer, for example 1/3 is a unit fraction. Such a representation is called
Egyptian Fraction as it was used by ancient Egyptians.

Note: dr > nr
*/

#include <bits/stdc++.h>

using namespace std;

void solve(int nr, int dr)
{
    if (nr == 0 || dr == 0) {
        return;
    }

    if (dr%nr == 0) {
        cout<<"1 \ "<<dr/nr<<endl;
        return;
    }

    int x = dr/nr + 1;
    cout<<"1 \ "<<x<<endl;
    solve((nr * x)-dr, dr*x);
}

int main()
{
    int nr, dr;

    cin>>nr>>dr;
    solve(nr, dr);

    return 0;
}
