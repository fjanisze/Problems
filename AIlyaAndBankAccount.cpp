//http://codeforces.com/problemset/problem/313/A
#include <iostream>
using namespace std;

using ll = long long;

int main()
{
    ll n;
    cin >> n;
    if(n>=0)
        cout<<n<<endl;
    else
    {
        n = abs(n);
        ll a = n/10;
        ll b = (n/100)*10 + n%10;
        cout<<-min(a,b)<<endl;
    }
}
