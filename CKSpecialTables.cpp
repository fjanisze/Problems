//http://codeforces.com/contest/625/problem/C
#include <iostream>
using namespace std;

int main()
{
    int n,k;
    cin >> n >> k;
    int r{n*n}, l{1};
    int ans{0},cur{r-(n-k)};
    for(int i{0};i<n;i++)
    {
        //cout<<cur<<endl;
        ans += cur;
        cur  = cur-1-(n-k);
    }
    cout<<ans<<endl;
    cur = (r-(n-k));
    for(int i{1};i<=n;i++)
    {
        for(int j{1};j<k;j++)
            cout<<l++<<" ";
        for(int j{cur},q{0};q<=(n-k);q++)
        {
            cout<<j+q<<" ";
        }
        cur = (cur-1-(n-k));
        cout<<endl;
    }
}
