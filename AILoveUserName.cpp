//http://codeforces.com/problemset/problem/155/A
#include <iostream>
using namespace std;

int main()
{
    long points,ans{0},mn{10001},mx{-1};
    int n;
    cin >> n;
    for(int i{0};i<n;i++)
    {
        cin>>points;
        if(mx>=0&&points>mx) ++ans;
        if(mn<10001&&points<mn) ++ans;
        mx=max(points,mx);
        mn=min(points,mn);
    }
    cout<<ans<<endl;
}
