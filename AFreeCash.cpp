//http://codeforces.com/problemset/problem/237/A
#include <iostream>
#include <map>
using namespace std;

int main()
{
    int n;
    cin >> n;
    map<int,int> load;
    int h,m,ans{0};
    for(int i{0};i<n;i++)
    {
        cin>>h>>m;
        ans=max(ans,++load[h*60+m]);
    }
    cout<<ans<<endl;
}
