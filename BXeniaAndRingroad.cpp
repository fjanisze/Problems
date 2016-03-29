//http://codeforces.com/problemset/problem/339/B
#include <iostream>
using namespace std;

using ll = long long;

int main()
{
    ll n,m,ans{0};
    cin>>n>>m;
    ll t,c{1};
    for(ll i{0};i<m;i++)
    {
        cin>>t;
        if(t>=c)
        {
            ans += (t-c);
        }else{
            ans += (n-c)+t;
        }
        c = t;
    }
    cout<<ans<<endl;
}
