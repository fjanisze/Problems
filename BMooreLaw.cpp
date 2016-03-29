//http://codeforces.com/contest/630/problem/B
#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

using ld = long double;

const ld mult{1.000000011};

int main()
{
    ld n,t;
    cin >> n >> t;
    ld r{n};
    r = pow((ld)mult,(ld)t)*(ld)n;
    cout<<setprecision(35)<<r<<endl;
}
