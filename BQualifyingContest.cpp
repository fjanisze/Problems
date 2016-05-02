//http://codeforces.com/contest/659/problem/B
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

#define readi(start,end,data) for(size_t i{start};i<end;i++) cin>>data[i];
#define printv(data) {for(auto& e:data) cout<<e<<","; cout<<endl;}
#define sortv(data) std::sort(data.begin(),data.end());
#define rsortv(data) std::sort(data.rbegin(),data.rend());
#define fori(start,end) for(size_t i{start};i<end;i++)
#define forj(start,end) for(size_t j{start};j<end;j++)
constexpr size_t min(size_t a,size_t b){ return a<b?a:b; }
constexpr size_t max(size_t a,size_t b){ return a>b?a:b; }

struct partecipant
{
    string surname;
    int points;
    partecipant(string sn,int pt):
        surname{sn},points{pt}{}
    bool operator<(const partecipant& other){
        return points>other.points;
    }
};

std::vector<partecipant> regions[10001];

int main()
{
    ios_base::sync_with_stdio(false);
    string surname;
    int reg,pts;
    int n,m;
    cin>>n>>m;
    set<int> reg_idx;
    while(n--){
        cin>>surname;
        cin>>reg;
        cin>>pts;
        regions[reg].emplace_back(partecipant(std::move(surname),pts));
        reg_idx.insert(reg);
    }
    for(auto e:reg_idx){
        sortv(regions[e]);
        bool ok{true};
        if(regions[e].size()>2){
            if(regions[e][2].points==regions[e][1].points)
                ok=false;
        }
        if(ok){
            cout<<regions[e][0].surname<<" "<<regions[e][1].surname<<endl;
        }else
            cout<<"?\n";
    }

    return 0;
}
