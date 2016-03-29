//http://codeforces.com/problemset/problem/318/A
#include <iostream>
using namespace std;

using ll = long long;

int main()
{
    ll n, k;
    cin >> n >> k;
    if(n%2!=0) ++n;
    if(k>n/2)
        cout<<(k-n/2)*2<<endl;
    else
        cout<<(2*k)-1<<endl;
}
