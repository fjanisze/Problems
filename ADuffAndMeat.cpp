//http://codeforces.com/problemset/problem/588/A
#include <iostream>
using namespace std;

using ll = long long;

int main()
{
    int n;
    cin >> n;
    ll ans{0},price{100000},q,p;
    for(int i{0};i<n;i++)
    {
        cin>>q>>p;
        price=min(price,p);
        ans+=q*price;
    }
    cout<<ans<<endl;
}
