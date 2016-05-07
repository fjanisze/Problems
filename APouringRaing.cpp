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
constexpr long double pi{3.1415926535897};

using ll = long long;

int main()
{
    ios_base::sync_with_stdio(false);
    long double d,h,v,e;
    cin >> d >> h >> v >> e;
    v/=(double)std::pow((double)d/2,2)*pi;
    if(e<v){
        cout<<"YES\n"<<h/(v-e)<<endl;
    }else{
        cout<<"NO\n";
    }
    return 0;
}
