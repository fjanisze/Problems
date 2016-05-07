//http://codeforces.com/contest/299/problem/A
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
    cin >> n;
    std::vector<ll> data(n);
    readi(0,n,data);
    sortv(data);
    ll n_min = data[0];
    fori(1,n){
        if(data[i]%n_min!=0){
            cout<<-1<<endl;
            return 0;
        }
    }
    cout<<n_min<<endl;
    return 0;
}

