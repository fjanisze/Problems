//http://codeforces.com/problemset/problem/581/A
#include <iostream>
using namespace std;

int main()
{
    int a,b;
    cin>>a>>b;
    int c{min(a,b)};
    cout<<c<<" ";
    a=max(a,b)-c;
    cout<<a/2<<endl;
}
