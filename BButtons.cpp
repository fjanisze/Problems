//http://codeforces.com/problemset/problem/268/B
#include <iostream>
using namespace std;

using ll = long long;

int main()
{
    ll n,ans{0};
    cin >> n;
    ans += n;
    for(long i{2};i<n;i++)
    {
        ans += (1+i*(n-i));
    }
    cout<<ans+(n>1)<<endl;
}
