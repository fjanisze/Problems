//http://codeforces.com/contest/691/problem/D
#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <map>
#include <queue>
#include <set>
#include <unordered_map>
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

std::unordered_map<ll,bool> visited;
std::unordered_map<ll,std::vector<ll>> data;
std::vector<ll> nums;

void dfs(ll root,std::set<ll>& d,std::set<ll>& nm)
{
 /*   if(visited[root])
        return;
    visited[root] = true;
    d.push_back(root);
    nm.push_back(nums[root]);
    for(auto e:data[root]){
        dfs(e,d,nm);
    }
    */
    std::queue<ll> Q;
    Q.push(root);
    while(!Q.empty()){
        ll root = Q.front();
        Q.pop();
        d.insert(root);
        nm.insert(nums[root]);
        visited[root] = true;
        for(auto& e:data[root]){
            if(!visited[e]){
                Q.push(e);
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    get(n);
    get(m);
    nums.resize(1+n);
    fori(1,n)
            cin>>nums[i];
    ll a,b;
    fori(1,m){
        cin >> a >> b;
        visited[b] = false;
        visited[a] = false;
        data[a].push_back(b);
        data[b].push_back(a);
    }
    fori(1,n){
        std::set<ll> idx,num;
        if(visited[i]==false){
            dfs(i,idx,num);
            auto nmi = num.rbegin();
            for(auto& i:idx)
            {
                nums[i] = *nmi;
                nmi++;
            }
        }
    }
    fori(1,n){
        cout<<nums[i]<<" ";
    }
    cout<<endl;

    return 0;
}
