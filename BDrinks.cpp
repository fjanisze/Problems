//http://codeforces.com/problemset/problem/200/B
#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

#define readi(start,end,data) for(size_t i{start};i<end;i++) cin>>data[i];
#define printv(data) for(auto& e:data) cout<<e<<","; cout<<endl;
#define sortv(data) std::sort(data.begin(),data.end());
#define rsortv(data) std::sort(data.rbegin(),data.rend());
#define fori(start,end) for(size_t i{start};i<end;i++)
#define forj(start,end) for(size_t j{start};j<end;j++)
constexpr size_t min(size_t a,size_t b){ return a<b?a:b; }
constexpr size_t max(size_t a,size_t b){ return a>b?a:b; }

int main()
{
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    vector<int> d(n);
    fori(0,n)
        cin>>d[i];
    long double fraction{0};
    fori(0,n){
        fraction+=d[i]/100.0;
    }
    cout<<setprecision(15)<<100*fraction/(long double)n<<endl;
    return 0;
}
