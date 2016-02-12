//http://codeforces.com/problemset/problem/624/B
#include <vector>
#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

using ll = long long;

int main()
{
    cout.sync_with_stdio(false);
    int n;
    cin >> n;
    vector<ll> data(n);
    for(int i{0};i<n;i++)
        cin >> data[i];
    sort(data.rbegin(),data.rend());
    ll ans{0};
    set<ll> ex;
    for(auto e:data)
    {
        ll cur{e};
        while(ex.insert(cur).second==false)
            --cur;
        if(cur>0)
            ans += cur;
    }
    cout<<ans<<endl;
}
