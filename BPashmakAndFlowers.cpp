//http://codeforces.com/problemset/problem/459/B
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

#define readi(start,end,data) for(size_t i{start};i<end;i++) cin>>data[i];
#define printv(data) for(auto& e:data) cout<<e<<","; cout<<endl;
#define sortv(data) std::sort(data.begin(),data.end());
#define rsortv(data) std::sort(data.rbegin(),data.rend());
#define fori(start,end) for(size_t i{start};i<end;i++)
#define forj(start,end) for(size_t j{start};j<end;j++)
constexpr size_t min(size_t a,size_t b){ return a<b?a:b; }
constexpr size_t max(size_t a,size_t b){ return a>b?a:b; }

using ll = long long;

int main()
{
    ios_base::sync_with_stdio(false);
    ll n;
    cin>>n;
    vector<ll> d(n);
    fori(0,n) cin>>d[i];
    sortv(d);
    ll smaller{1},higher{1};
    fori(1,n)
        if(d[i]==d[i-1]) ++smaller;
        else break;
    for(ll i{n-2};i>=0;i--)
        if(d[i]==d[i+1]) ++higher;
        else break;
    cout<<d.back()-d.front()<<" ";
    if(d.front()==d.back())
        cout<<(n*(n-1))/2<<endl;
    else
        cout<<smaller*higher<<endl;
    return 0;
}

