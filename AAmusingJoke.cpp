//http://codeforces.com/problemset/problem/141/A
#include <iostream>
#include <string>
using namespace std;

constexpr int size{'Z'-'A'};
int chars[size];

int main()
{
    string guest,host,pile;
    cin>>guest>>host>>pile;
    for(auto c:guest)
        ++chars[c-'A'];
    for(auto c:host)
        ++chars[c-'A'];
    for(auto e:pile)
    {
        if(--chars[e-'A']<0){
            cout<<"NO\n";
            return 0;
        }
    }
    for(int i{0};i<size;i++)
        if(chars[i]>0){
            cout<<"NO\n";
            return 0;
        }
    cout<<"YES\n";
}
