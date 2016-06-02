//http://codeforces.com/contest/631/problem/B
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

ll sequence[2][5001];
ll proper_color[2][5001];

int main()
{
    ios_base::sync_with_stdio(false);
    get(y);
    get(x);
    get(k);
    ll sequence_nbr{1};
    fori(0,k-1)
    {
        get(op);
        get(pos);
        get(color);
        if(op==1) //y
        {
            proper_color[0][pos-1] = color;
            sequence[0][pos-1] = sequence_nbr++;
        }
        else //x
        {
            proper_color[1][pos-1] = color;
            sequence[1][pos-1] = sequence_nbr++;
        }
    }
    //Paint with the final color
    fori(0,y-1){
        forj(0,x-1){
            if(sequence[0][i]>sequence[1][j])
                cout<<proper_color[0][i]<<" ";
            else
                cout<<proper_color[1][j]<<" "   ;
        }
        cout<<endl;
    }
    return 0;
}

