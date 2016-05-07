//http://codeforces.com/problemset/problem/670/D2
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define printv(data) for(auto& e:data) cout<<e<<","; cout<<endl;
#define sortv(data) std::sort(data.begin(),data.end());
#define rsortv(data) std::sort(data.rbegin(),data.rend());

#define fori(start,end) for(size_t i{start};i<end;i++)
#define forj(start,end) for(size_t j{start};j<end;j++)

#define foralli(data) fori(0,data.size())

constexpr size_t min(size_t a,size_t b){ return a<b?a:b; }
constexpr size_t max(size_t a,size_t b){ return a>b?a:b; }

using ll = long long;
using vll = std::vector<ll>;

#define get(var_name) ll var_name{0}; cin >> var_name;
#define readv(start,end,vec_name) std::vector<ll> vec_name(end); for(size_t i{start};i<end;i++) cin>>vec_name[i];

constexpr ll BIGLL{ std::numeric_limits<ll>::max() };
constexpr ll LL10{ 10000000000 + 1 };

bool check(vll cookie,vll ingred,ll k,ll num){
    foralli(cookie){
        ll delta = ingred[i] - cookie[i]*num;
        if(delta<0){
            delta*=-1;
            if(delta<=k){
                k -= delta;
            }else{
                return false;
            }
        }
    }
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    get(n);
    get(k);
    readv(0,n,cookie);
    readv(0,n,ingred);
    ll l{0},r{LL10};
    while(l<=r){
        ll m{(l+r)/2};
        if(check(cookie,ingred,k,m)){
            l = m + 1;
        }else{
            r = m - 1;
        }
    }
    cout<<r<<endl;
    return 0;
}
