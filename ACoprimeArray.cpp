#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
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

ll gcd(ll a,ll b)
{
    if(b==0) return a;
    return gcd(b,a%b);
}

int main()
{
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    vector<ll> data(n);
    readi(0,n,data);
    vector<ll> idx(n,-1);
    ll cnt{0};
    fori(1,n){
        if(gcd(data[i-1],data[i])!=1){
            idx[i-1]=i-1;
            ++cnt;
        }
    }
    cout<<cnt<<endl;
    fori(0,n){
        cout<<data[i]<<" ";
        if(idx[i]>=0){
            forj(2,1e9){
                if(gcd(data[i],j)==1&&gcd(data[i+1],j)==1){
                    cout<<j<<" ";
                    break;
                }
            }
        }
    }
    return 0;
}

