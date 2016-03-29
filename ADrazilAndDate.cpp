//http://codeforces.com/problemset/problem/515/A
#include <iostream>
#include <cmath>
using namespace std;

using ll=long long;

int main()
{
    ll a,b,s;
    cin>>a>>b>>s;
    a=abs(a);
    b=abs(b);
    if((a+b)>s || (s-(a+b))%2!=0)
        cout<<"NO\n";
    else
        cout<<"YES\n";
}
