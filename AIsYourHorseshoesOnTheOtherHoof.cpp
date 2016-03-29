//http://codeforces.com/problemset/problem/228/A
#include <iostream>
#include <map>
using namespace std;

using ll = long long;

int main()
{
    map<ll,int> cnt;
    ll t{0};
    for(int i{0};i<4;i++)
    {
        cin >> t;
        ++cnt[t];
    }
    int ans{0};
    for(auto e:cnt)
    {
        ans += (e.second-1);
    }
    cout<<ans<<endl;
}
