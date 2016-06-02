//http://codeforces.com/contest/676/problem/B
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
auto min(t&& a,t2&& b) -> decltype(a+b){ return a < b ? a : b; }

template<typename t,typename t2>
auto max(t&& a,t2&& b) -> decltype(a+b){ return a > b ? a : b; }

template<typename N>
N multimax_impl(N cur,N last)
{   return max(cur,last);   }

template<typename N,typename...VALS>
N multimax_impl(N cur,N n,VALS...vals)
{   return multimax_impl(max(cur,n),vals...);   }

template<typename N,typename...VALS>
N multimax(N f,VALS...values)
{   return multimax_impl(std::numeric_limits<N>::min(),f,values...); }

template<typename T>
T pow(T n,T e){
    T r{1};
    while(e--)
        r*=n;
    return r;
}


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

ld levels[100][11];
ll maxle{0};
ll cur{0};

#include <memory>

void fillll(ll level,ll index,ld shit)
{
    if(level > maxle) return;
    levels[index][level] += shit;
    if(levels[index][level]>1){
        shit = levels[index][level] - 1;
          levels[index][level] = 1;
    }else shit = 0;
    if(shit>0){
        fillll(level+1,index-1,shit/2);
        fillll(level+1,index+1,shit/2);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    ll n,t;
    cin >> n >> t;
    maxle = n;
    while(t>0){
        fillll(1,10,1);
        --t;
    }
    ll ans{0};
    fori(0,11)
      {
        forj(0,40)
                if(levels[j][i]==1)
                ++ans;
    }
    cout<<ans<<endl;

    return 0;
}
