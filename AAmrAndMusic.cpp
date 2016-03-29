#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

#define readi(start,end,data) for(size_t i{start};i<end;i++) cin>>data[i];
#define printv(data) for(auto& e:data) cout<<e<<","; cout<<endl;
#define sortv(data) std::sort(data.begin(),data.end());
#define rsortv(data) std::sort(data.rbegin(),data.rend());
#define fori(start,end) for(size_t i{start};i<end;i++)
#define forj(start,end) for(size_t j{start};j<end;j++)
constexpr min(size_t a,size_t b){ return a<b?a:b; }
constexpr max(size_t a,size_t b){ return a>b?a:b; }

stack<int> mapping[101];

int main()
{
    ios_base::sync_with_stdio(false);
    int n,k;
    cin>>n>>k;
    std::vector<int> data(n);
    readi(0,n,data);
    fori(0,n)
    {
        mapping[data[i]].push(i+1);
    }
    sortv(data);
    int ans{0};
    fori(0,n)
    {
        k-=data[i];
        if(k>=0) ++ans;
        else break;
    }
    cout<<ans<<endl;
    fori(0,ans)
    {
        cout<<mapping[data[i]].top()<<" ";
        mapping[data[i]].pop();
    }
    cout<<endl;
    return 0;
}

