//http://codeforces.com/contest/675/problem/B
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

using ll = long long;
using ld = long double;
using pll = std::pair<ll,ll>;
using vpll = std::vector<pll>;
using vll = std::vector<ll>;

constexpr ll BIGLL{ std::numeric_limits<ll>::max() };
constexpr ld BIGLD{ std::numeric_limits<ld>::max() };
constexpr ll LL10{ 10000000000 + 1 };

template<typename t,typename t2>
auto min(t&& a,t2&& b) -> decltype(a+b){   return a < b ? a : b;   }

template<typename t,typename t2>
auto max(t&& a,t2&& b) -> decltype(a+b){   return a > b ? a : b;   }

template<typename N>
ll multimax_impl(ll cur,N last)
{   return max(cur,last);   }

template<typename N,typename...VALS>
ll multimax_impl(ll cur,N n,VALS...vals)
{   return multimax_impl(max(cur,n),vals...);   }

template<typename...VALS>
ll multimax(VALS...values)
{   return multimax_impl(-BIGLL,values...); }

#define get(var_name) ll var_name{0}; cin >> var_name;
#define gets(var_name) std::string var_name; cin >> var_name;
#define readv(start,end,vec_name) std::vector<ll> vec_name(end); for(size_t i{start};i<end;i++) cin>>vec_name[i];
#define getpll(llp) std::cin>>llp.first>>llp.second;


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

constexpr bool check(ll n,ll l)
{
    return (n>=1&&n<=l);
}

int main()
{
    ios_base::sync_with_stdio(false);
    get(n); get(a);
    get(b); get(c);
    get(d);
/*    ll ans{0};
    fori(1,n){
        ll y = i+b-c;
        ll z = i+a+b-c-d;
        ll w = i+a-d;
        if(check(y,n)&&check(z,n)&&check(w,n))
            ans += n;
    }
    cout<<ans<<endl; */
    ll t = multimax(a + b + 1,a + c + 1,c + d + 1,b + d + 1);
    t = multimax(t - a - b,t - a - c, t - c - d,t - b - d);
    if(n<t)
        cout<<0<<endl;
    else{
        cout<<n * (n - t + 1)<<endl;
    }
    return 0;
}
