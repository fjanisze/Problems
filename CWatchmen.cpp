//http://codeforces.com/contest/651/problem/C
#include <iostream>
#include <utility>
#include <map>
using namespace std;

using ll = long long;

map<ll,ll> x;
map<ll,ll> y;
map<pair<ll,ll>,long> xy;

int main()
{
    ll n,ans{0};
    cin >> n;
    for(long i{0};i<n;i++)
    {
        ll a,b;
        cin >> a >> b;
        ans += x[a]++;
        ans += y[b]++;
        ans -= xy[make_pair(a,b)]++;
    }
    cout<<ans<<endl;
}
