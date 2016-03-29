//http://codeforces.com/problemset/problem/617/A
#include <iostream>
using namespace std;

int main()
{
    int x,ans;
    cin >> x;
    if(x<=5)
        ans = 1;
    else
        ans = x/5 + (x%5!=0);
    cout<<ans<<endl;
}
