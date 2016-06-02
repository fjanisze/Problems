#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <fstream>
#include <random>
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

ll nodes[100002];
ll pointers[5*100005];

/*
int main()
{
    ofstream outfile("data.dat");
    outfile << 90000;
    random_device rd;
    default_random_engine end(rd());
    uniform_int_distribution<> dist(0,1000000);
    fori(0,89999)
    {
        outfile<<dist(end)<<" ";
    }
    outfile<<endl;
}*/

int main()
{
    ios_base::sync_with_stdio(false);
    get(n);
    ll value;
    fori(0,5*100005)
        pointers[i] = -1; //null pointers
    pointers[0] = 0;
    get(root);
    nodes[0] = root;
    ll pos,parent;
    fori(1,n-1){
        pos = 0;
        parent = 0;
        cin >> value;
        nodes[i] = value;
        while(pointers[pos]!=-1)
        {
            parent = pos;
            if(value > nodes[pointers[pos]])
                pos = 1 + pointers[parent]*2 + 1;
            else
                pos = 1 + pointers[parent]*2;
        }
        if(value > nodes[pointers[parent]]){
            pointers[1 + pointers[parent]*2 + 1] = i;
        }
        else{
            pointers[1 + pointers[parent]*2] = i;
        }
        cout<<nodes[pointers[parent]]<<" ";
    }
    cout<<endl;
    return 0;
}

