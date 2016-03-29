//http://codeforces.com/problemset/problem/577/A
#include <iostream>
using namespace std;

using ll=long long;

int main()
{
    ll n,x,ans{0};
    cin>>n>>x;
    for(ll div{1};div<=n;div++)
    {
        if(x%div==0 && (x/div<=n)){
            ++ans;
        }
    }
    cout<<ans<<endl;
}
