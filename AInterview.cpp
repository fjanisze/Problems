//http://codeforces.com/contest/631/problem/A
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define printv(data) for(auto& e:data) cout<<e<<","; cout<<endl;
#define sortv(data) std::sort(data.begin(),data.end());
#define rsortv(data) std::sort(data.rbegin(),data.rend());

#define fori(start,end) for(size_t i{start};i<=end;i++)
#define forj(start,end) for(size_t j{start};j<=end;j++)
#define rofi(start,end) for(size_t i{start};i>=end;i--)

#define foralli(data) fori(0,data.size())

template<typename T,typename T2>
auto min(T&& a,T2&& b) -> decltype(a+b){   return a < b ? a : b;   }

template<typename T,typename T2>
auto max(T&& a,T2&& b) -> decltype(a+b){   return a > b ? a : b;   }

using ll = long long;
using ld = long double;
using vll = std::vector<ll>;

#define get(var_name) ll var_name{0}; cin >> var_name;
#define gets(var_name) std::string var_name; cin >> var_name;
#define readv(start,end,vec_name) std::vector<ll> vec_name(end); for(size_t i{start};i<end;i++) cin>>vec_name[i];

constexpr ll BIGLL{ std::numeric_limits<ll>::max() };
constexpr ld BIGLD{ std::numeric_limits<ld>::max() };
constexpr ll LL10{ 10000000000 + 1 };

int main()
{
    ios_base::sync_with_stdio(false);
    get(n);
    readv(0,n,first);
    readv(0,n,second);
    fori(0,n-1)
    {
        first[0] |= first[i];
        second[0] |= second[i];
    }
    cout<<first[0]+second[0]<<endl;
    return 0;
}

