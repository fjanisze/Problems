//http://codeforces.com/contest/299/problem/B
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
    ll n,k;
    cin >> n >> k;
    vector<char> data(n);
    readi(0,n,data);
    if(data.back()=='#'){
        cout<<"NO\n";
    }else{
        ll cnt{0};
        fori(0,n){
            if(data[i]=='#')
                ++cnt;
            else
                cnt = 0;
            if(cnt>=k){
                cout<<"NO\n";
                return 0;
            }
        }
    }
    cout<<"YES\n";
    return 0;
}
