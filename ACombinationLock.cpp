//http://codeforces.com/problemset/problem/540/A
#include <iostream>
using namespace std;

char pos[1000];

int main()
{
    int n,ans{0};
    cin >> n;
    for(int i{0};i<n;i++)
    {
        cin>>pos[i];
        pos[i]-='0';
    }
    for(int i{0};i<n;i++)
    {
        char t;
        cin >> t;
        t-='0';
        ans += min(abs(pos[i]-t),min(9-pos[i]+t+1,9-t+pos[i]+1));
    }
    cout<<ans<<endl;
}
