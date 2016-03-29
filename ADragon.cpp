//http://codeforces.com/problemset/problem/230/A
#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main()
{
    int s,n,x,y;
    cin>>s>>n;
    map<int,vector<int>> dragons;
    for(int i{0};i<n;i++)
    {
        cin>>x>>y;
        dragons[x].push_back(y);
    }
    for(auto& e:dragons)
    {
        if(e.first>=s){
            cout<<"NO\n";
            return 0;
        }
        for(auto& ds:e.second)
            s+=ds;
    }
    cout<<"YES\n";
}
