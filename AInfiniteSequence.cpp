//http://codeforces.com/contest/622/problem/A
#include <iostream>
#include <cmath>
using namespace std;

using ll = long long;

int main()
{
    ll n;
    cin >> n;
    ll c{0},k{0};
    while(c+k<n)
    {
        c += k;
        ++k;
    }
    cout<<n-c<<endl;
}
