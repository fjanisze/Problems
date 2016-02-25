//http://codeforces.com/problemset/problem/630/N
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

using ld = long double;

ld mpow(ld b,ld e)
{
    ld r{1};
    while(e--)
        r *= b;
    return r;
}

int main()
{
    ld a,b,c;
    cin >> a >> b >> c;
    ld root1 = (-b + (ld)sqrt((ld)(mpow(b,2)-4*a*c)))/(2*a);
    ld root2 = (-b - (ld)sqrt((ld)(mpow(b,2)-4*a*c)))/(2*a);
    cout<<setprecision(16)<<max(root1,root2)<<endl;
    cout<<setprecision(16)<<min(root1,root2)<<endl;
}
