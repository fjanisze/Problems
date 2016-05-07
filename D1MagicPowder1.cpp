//http://codeforces.com/problemset/problem/670/D1
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

#define printv(data) for(auto& e:data) cout<<e<<","; cout<<endl;
#define sortv(data) std::sort(data.begin(),data.end());
#define rsortv(data) std::sort(data.rbegin(),data.rend());
#define fori(start,end) for(size_t i{start};i<end;i++)
#define forj(start,end) for(size_t j{start};j<end;j++)
constexpr size_t min(size_t a,size_t b){ return a<b?a:b; }
constexpr size_t max(size_t a,size_t b){ return a>b?a:b; }

using ll = long long;

#define get(var_name) ll var_name{0}; cin >> var_name;
#define readv(start,end,vec_name) std::vector<ll> vec_name(end); for(size_t i{start};i<end;i++) cin>>vec_name[i];

constexpr ll BIGLL{ std::numeric_limits<ll>::max() };

int main()
{
    ios_base::sync_with_stdio(false);
    get(n);
    get(k);
    readv(0,n,cookie);
    readv(0,n,ingred);
    ll missing{0},ans{0};
    bool boke{true};
    std::vector<ll> tmp_ing(n);
    while(1){
        fori(0,n){
            if(cookie[i]>ingred[i]){
                missing = cookie[i]-ingred[i];
                if(missing>k){
                    boke = false;
                    break;
                }else{
                    k -= missing;
                    missing = 0;
                }
                tmp_ing[i] = 0;
            }else
                tmp_ing[i] = ingred[i] - cookie[i];
        }
        if(boke){
            ++ans;
            std::swap(tmp_ing,ingred);
        }else break;
    }
    cout<<ans<<endl;
    return 0;
}
