//http://codeforces.com/problemset/problem/630/K
#include <iostream>
using namespace std;

using ll = long long;

int main()
{
    ll n;
    cin >> n;
    //This is just a inclusion-exclusion principle application
    ll r{n};
    r -= (n/7+n/5+n/3+n/2);
    r += (n/14+n/21+n/35+n/15+n/10+n/6);
    r -= (n/42+n/105+n/30+n/70);
    r += (n/210);
    cout<<r<<endl;
}
