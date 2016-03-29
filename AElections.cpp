//http://codeforces.com/problemset/problem/570/A
#include <iostream>
#include <map>
using namespace std;

using ll = long long;

int main()
{
    int n,m;
    cin>>n>>m;
    map<ll,ll> city_winner;
    ll mx{0},winner{1},vote;
    for(int i{1};i<=m;i++)
    {
        mx=0;
        winner=1;
        for(int j{1};j<=n;j++)
        {
            cin>>vote;
            if(vote>mx){
                winner = j;
                mx=vote;
            }
        }
        ++city_winner[winner];
    }
    mx=0; winner=1;
    for(auto e:city_winner)
    {
        if(e.second>mx){
            winner=e.first;
            mx=e.second;
        }
    }
    cout<<winner<<endl;
    return 0;
}
