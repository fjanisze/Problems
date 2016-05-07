#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <map>
using namespace std;

#define readi(start,end,data) for(size_t i{start};i<end;i++) cin>>data[i];
#define printv(data) for(auto& e:data) cout<<e<<","; cout<<endl;
#define sortv(data) std::sort(data.begin(),data.end());
#define rsortv(data) std::sort(data.rbegin(),data.rend());
#define fori(start,end) for(size_t i{start};i<end;i++)
#define forj(start,end) for(size_t j{start};j<end;j++)
constexpr size_t min(size_t a,size_t b){ return a<b?a:b; }
constexpr size_t max(size_t a,size_t b){ return a>b?a:b; }

using ll = long long;

struct lang_data
{
    ll index{0};
    ll count{0};
    bool operator<(const lang_data& other){
        return count > other.count;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    ll n;
    cin >> n;
    vector<ll> scilang(n);
    readi(0,n,scilang);
    ll m;
    cin >> m;
    vector<ll> ciaudio(m),
            cisub(m);
    readi(0,m,ciaudio);
    readi(0,m,cisub);

    std::map<ll,lang_data> lang_counter;

    for(auto e:scilang){
        lang_counter[e].index = e;
        ++lang_counter[e].count;
    }

    ll max_sci{0};
    ll ans{-1};

    fori(0,ciaudio.size()){
        if(lang_counter[ciaudio[i]].count > max_sci){
         //   cout<<"M: "<<ciaudio[i]<<endl;
            max_sci = lang_counter[ciaudio[i]].count;
            ans = i;
        }else if(lang_counter[ciaudio[i]].count == max_sci){
       //     cout<<"S:"<<lang_counter[cisub[ans]].count<<" "<<lang_counter[cisub[i]].count<<endl;
            if(lang_counter[cisub[ans]].count < lang_counter[cisub[i]].count){
                ans = i;
            }
        }
    }
    cout<<(ans>=0?ans+1:1)<<endl;
    return 0;
}
