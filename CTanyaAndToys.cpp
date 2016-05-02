//http://codeforces.com/contest/659/problem/C
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
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

inline
ll summ(ll a,ll b){
    ll t = a*(a+1)/2;
    return (b*(b+1)/2)-t+a;
}

int main()
{
    ios_base::sync_with_stdio(false);
    ll n,m,i{0};
    cin>>n>>m;
    vector<ll> data(n);
    while(n--)
    {
        cin>>data[i++];
    }
    sortv(data);
    ll s{1};
    i=0;
    ll c{0};
    vector<ll> toys;
    while(s<=1e9){
        if(data[i]==s){
            ++i;
            ++s;
            continue;
        }
        if(m-s>=0){
            ++c;
            toys.push_back(s);
            m-=s;
        }
        else break;
        ++s;
    }
  /*  i=0;
    {
        if(data[i]==s){
            while(data[i]==s){
                ++s;
                ++i;
            }
        }
    }
    */
    cout<<c<<endl;
    for(auto e:toys)
        cout<<e<<" ";
    cout<<endl;
    return 0;
}
