//http://codeforces.com/contest/602/problem/A
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

template<typename T>
T pow(T n,T e){
    T r{1};
    while(e--)
        r*=n;
    return r;
}

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

int main()
{
    ios_base::sync_with_stdio(false);
    get(n1);
    get(b1);
    readv(0,n1,base1);
    get(n2);
    get(b2);
    readv(0,n2,base2);
    ll a{0},b{0};
    fori(0,n1-1){
        a += pow(b1,n1-i-1)*base1[i];
    }
    fori(0,n2-1){
        b += pow(b2,n2-i-1)*base2[i];
    }
    if(a<b)
        cout<<"<\n";
    else if(a>b)
        cout<<">\n";
    else
        cout<<"=\n";
    return 0;
}

