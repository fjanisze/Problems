#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

#define printv(data) for(auto& e:data) cout<<e<<","; cout<<endl;
#define sortv(data) std::sort(data.begin(),data.end());
#define rsortv(data) std::sort(data.rbegin(),data.rend());

#define fori(start,end) for(size_t i{start};i<end;i++)
#define forj(start,end) for(size_t j{start};j<end;j++)

#define foralli(data) fori(0,data.size())

constexpr size_t min(size_t a,size_t b){ return a<b?a:b; }
constexpr size_t max(size_t a,size_t b){ return a>b?a:b; }

using ll = long long;
using vll = std::vector<ll>;

#define get(var_name) ll var_name{0}; cin >> var_name;
#define gets(var_name) std::string var_name; cin >> var_name;
#define readv(start,end,vec_name) std::vector<ll> vec_name(end); for(size_t i{start};i<end;i++) cin>>vec_name[i];

constexpr ll BIGLL{ std::numeric_limits<ll>::max() };
constexpr ll LL10{ 10000000000 + 1 };

int main()
{
    ios_base::sync_with_stdio(false);
    get(n);
    gets(text);
    map<char,ll> count;
    ll ans{0};
    ll rem{26};
    fori(0,n){
        ++count[text[i]];
        if(count[text[i]]==1){
            --rem;
        }else{
            --rem;
            ++ans;
        }
    }
    if(ans>26 || rem < 0)
        cout<<-1<<endl;
    else
        cout<<ans<<endl;

    return 0;
}
