//http://codeforces.com/contest/681/problem/C
#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <queue>
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

#include <map>
#include <sstream>
using namespace std;

std::string op[]={
    "insert", //0
    "removeMin", //1
    "getMin" //2
};

map<string,int> opsmap = {
    make_pair(op[0],0),
    make_pair(op[1],1),
    make_pair(op[2],2)
};

int main()
{
    ios_base::sync_with_stdio(false);
    ll n;
    cin >> n;
    std::priority_queue<ll, std::vector<ll>, std::greater<ll> > Q;
    std::string operation;
    stringstream result;
    ll num_of_ops{0};
    ll num;
    fori(1,n){
        cin >> operation;
        ll mp = opsmap[operation];
        switch(mp){
        case 0:
            cin >> num;
            Q.push(num);
            result<<operation<<" "<<num<<endl;
            ++num_of_ops;
            break;
        case 2:
            cin >> num;
            if(Q.empty()){
                result<<"insert "<<num<<endl;
                ++num_of_ops;
                Q.push(num);
            }
            if(Q.top()>num){
                result<<"insert "<<num<<endl;
                ++num_of_ops;
                Q.push(num);
            }
            else if(Q.top()<num){
                do{
                    Q.pop();
                    result<<"removeMin\n";
                    ++num_of_ops;
                }while(!Q.empty() && Q.top()<num);
                if(Q.top()!=num){
                    ++num_of_ops;
                    result<<"insert "<<num<<endl;
                    Q.push(num);
                }
            }
            ++num_of_ops;
            result<<operation<<" "<<num<<endl;
            break;
        case 1:
            if(Q.empty()){
                result<<"insert "<<0<<endl;
                Q.push(0);
                ++num_of_ops;
            }
            Q.pop();
            ++num_of_ops;
            result<<"removeMin\n";
            break;
        default:
            break;
        }
    }
    cout<<num_of_ops<<endl;
    cout<<result.str();
    return 0;
}
