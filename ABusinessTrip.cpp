//http://codeforces.com/problemset/problem/149/A
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
constexpr min(size_t a,size_t b){ return a<b?a:b; }

int main()
{
    int k;
    cin>>k;
    if(k==0){
        cout<<0<<endl;
        return 0;
    }
    vector<int> months(12);
    readi(0,12,months);
    rsortv(months);
    int ans{0},sum{0};
    fori(0,12)
    {
        sum+=months[i];
        if(sum>=k){
            ans=i+1;
            break;
        }
    }
    cout<<(sum<k?-1:ans)<<endl;
}

