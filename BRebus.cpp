//http://codeforces.com/contest/664/problem/B
#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <sstream>
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
constexpr ld pi = 3.141592653589793238462643383279502884;

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

ll prime_factors(ll n,std::vector<ll>& data){
    while(n%2==0){data.emplace_back(2);n/=2;}
    for(ll i{3};i<=sqrt(n);i+=2){while(n%i==0){data.emplace_back(i);n/=i;}}
    if(n>2) data.emplace_back(n);
    return data.size();
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

ll sol[101];

int main()
{
    ios_base::sync_with_stdio(false);
    ll n;
    std::string rebus;
    std::getline(std::cin,rebus);
    ll num_plus{0},num_minus{0};
    ll cnt{1};
    sol[0] = 1;
    for(std::size_t i{0};i<rebus.size();i++){
        char e = rebus[i];
        if(e=='+'){
            ++num_plus;
            sol[cnt++] = 1;
        }
        else if(e=='-'){
            ++num_minus;
            sol[cnt++] = -1;
        }
        else if(e=='='){
            n = std::stoi(rebus.substr(i+1));
            break;
        }
    }
    int sign{1};
    ll ans{0};

    for(int cur=0;cur<cnt;++cur)
    {
        sign = sol[cur];
        sol[cur] = 0;
        //cout<<"#:"<<ans<<" "<<sign<<endl;
        if(sign<0) --num_minus;
        else if(cur>0) --num_plus;
        for(int x{1};x<=n;x++){
            ll max_n = ans + x*sign + n*num_plus - num_minus;
            ll min_n = ans + x*sign + num_plus - n*num_minus;
            //cout<<min_n<<" "<<max_n<<" "<<x<<" : "<<num_plus<<","<<num_minus<<endl;
            if(max_n>=n && min_n<=n)
            {
                sol[cur] = x*sign;
                ans += sol[cur];
                break;
            }
        }
        if(sol[cur]==0){
            cout<<"Impossible\n";
            return 0;
        }
    }
    cout<<"Possible\n";
    cout<<sol[0]<<" ";
    for(int i{1};i<cnt;i++){
        if(sol[i]<0){
            cout<<" - "<<-1*sol[i]<<" ";
        }
        else
            cout<<" + "<<sol[i]<<" ";
    }
    cout<<"= "<<n<<endl;
    return 0;
}
