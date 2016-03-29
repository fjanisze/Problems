//http://codeforces.com/problemset/problem/61/A
#include <iostream>
#include <string>
using namespace std;

int main()
{
    string a,b;
    cin >> a >> b;
    for(size_t i{0};i<a.size();i++)
    {
        if(a[i]==b[i]) cout<<"0";
        else cout<<"1";
    }
    cout<<endl;
}
