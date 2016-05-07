#include <iostream>
#include <vector>
#include <algorithm>
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

int main()
{
    ios_base::sync_with_stdio(false);
    ll n,mi{10000000},ma{0};
    cin >> n;
    int day[] = {1,2,3,4,5,6,7};
    for(ll s{0};s<7;s++){
        ll work{0},off{0};
        for(ll i{0};i<n;i++){
            if(day[(s+i)%7]>=6)
                ++off;
            else
                ++work;
        }
        mi = min(mi, off);
        ma = max(ma, off);
    }
    cout<<mi<<" "<<ma<<endl;
    return 0;
}

