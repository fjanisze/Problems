//http://codeforces.com/problemset/problem/492/A
#include <iostream>
using namespace std;

int main()
{
    int n{1},t{3},ans{1},c;
    cin >> c;
    for(int k{3};n+t<=c;(n+=t,t+=k,++k))
    {
        ++ans;
    }
    cout<<ans<<endl;
}
