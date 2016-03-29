//http://codeforces.com/problemset/problem/427/A
#include <iostream>
using namespace std;

int main()
{
    cout.sync_with_stdio(false);
    int n,police_cnt{0},ans{0};
    cin >> n;
    for(int i{0};i<n;i++)
    {
        int t;
        cin>>t;
        if(t>0)
            police_cnt+=t;
        else if(police_cnt>0)
            --police_cnt;
        else ++ans;
    }
    cout<<ans<<endl;
}
