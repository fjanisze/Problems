#include <iostream>
#include <vector>
#include <algorithm>
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
using vll = std::vector<ll>;

#define get(var_name) ll var_name{0}; cin >> var_name;
#define gets(var_name) std::string var_name; cin >> var_name;
#define readv(start,end,vec_name) std::vector<ll> vec_name(end); for(size_t i{start};i<end;i++) cin>>vec_name[i];

constexpr ll BIGLL{ std::numeric_limits<ll>::max() };
constexpr ld BIGLD{ std::numeric_limits<ld>::max() };
constexpr ll LL10{ 10000000000 + 1 };

char op_to_perform[200001];

int main()
{
    ios_base::sync_with_stdio(false);
    get(n);
    get(m);
    readv(0,n,report);
    vector<pair<int,ll>> ops;
    pair<ll,ll> last_longest{0,0};
    fori(0,m-1){
        char op;
        cin >> op;
        get(limit);
        ops.push_back(make_pair(op,limit));
        if(limit>=last_longest.second){
            last_longest.second = limit;
            last_longest.first = i;
        }
    }

    ll current_limit{0};
    for(long i{m-1};i>=last_longest.first;i--)
    {
        if(ops[i].second>current_limit){
            op_to_perform[ops[i].second] = ops[i].first;
            current_limit = ops[i].second;
        }
    }

    sort(report.begin(),report.begin()+last_longest.second);

    ll cur_max{last_longest.second-1},cur_min{0};

    char current_op;
    std::vector<ll> ans;
    ans.reserve(n);
    for(std::size_t i{last_longest.second};i>0;i--)
    {
        if(op_to_perform[i]!=0){
            current_op = op_to_perform[i];
        }
        if(current_op=='2')
        {
            ans.push_back(report[cur_min++]);
        }
        else
        {
            ans.push_back(report[cur_max--]);
        }
    }
    fori(0,last_longest.second - 1)
    {
        cout<<ans[last_longest.second - 1 - i]<<" ";
    }
    fori(last_longest.second,n-1)
    {
        cout<<report[i]<<" ";
    }
    cout<<endl;

    return 0;
}
