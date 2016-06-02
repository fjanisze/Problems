//http://codeforces.com/contest/675/problem/A
#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;


#define printv(data) for(auto& e:data) cout<<e<<","; cout<<endl;
#define sortv(data) std::sort(data.begin(),data.end());
#define rsortv(data) std::sort(data.rbegin(),data.rend());

#define fori(start,end) for(size_t i{start};i<=end;i++)
#define forj(start,end) for(size_t j{start};j<=end;j++)
#define rofi(start,end) for(size_t i{start};i>end;i--)

#define foralli(data) fori(0,data.size())

template<typename T,typename T2>
auto min(T&& a,T2&& b) -> decltype(a+b){   return a < b ? a : b;   }

template<typename T,typename T2>
auto max(T&& a,T2&& b) -> decltype(a+b){   return a > b ? a : b;   }

using ll = long long;
using ld = long double;

using pll = std::pair<ll,ll>;
using vpll = std::vector<pll>;

using vll = std::vector<ll>;


#define get(var_name) ll var_name{0}; cin >> var_name;
#define gets(var_name) std::string var_name; cin >> var_name;
#define readv(start,end,vec_name) std::vector<ll> vec_name(end); for(size_t i{start};i<end;i++) cin>>vec_name[i];
#define getpll(llp) std::cin>>llp.first>>llp.second;


constexpr ll BIGLL{ std::numeric_limits<ll>::max() };
constexpr ld BIGLD{ std::numeric_limits<ld>::max() };
constexpr ll LL10{ 10000000000 + 1 };

//specific for codeforces
#ifndef ONLINE_JUDGE
#define Log(...) fprintf (stdout, __VA_ARGS__);
#define LogN(num) fprintf (stdout, "@: %l64d\n", num);
#define LogS(str) fpringf (stdout, "@: %s\n", str.c_str());
#else
#define Log(...)
#define LogN(num)
#define LogS(str)
#endif

int main()
{
    ios_base::sync_with_stdio(false);
    get(a);
    get(b);
    get(c);
    if(c==0)
    {
        if(a==b)
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }else{
        b-=a;
        if(b>0 && c<0)
            cout<<"NO\n";
        else if(b<0 && c>0)
            cout<<"NO\n";
        else if(b%c==0)
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
