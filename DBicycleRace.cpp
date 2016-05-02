//http://codeforces.com/contest/659/problem/D
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

int main()
{
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    ++n;
    vector<pair<int,int>> coords(n);
    fori(0,n)
    {
        cin>>coords[i].first>>coords[i].second;
    }
    //0-top
    //1=right
    //2=bottom
    //3=left
    int currentDir{0},ans{0};
    fori(1,n){
        int newDir;
        if(coords[i].first>coords[i-1].first){
            newDir=1;
        }else if(coords[i].first<coords[i-1].first){
            newDir=3;
        }
        if(coords[i].second>coords[i-1].second){
            newDir=0;
        }else if(coords[i].second<coords[i-1].second){
            newDir=2;
        }
        if(newDir==(currentDir+3)%4)
            ++ans;
        currentDir=newDir;
    }
    cout<<ans<<endl;
    return 0;
}

