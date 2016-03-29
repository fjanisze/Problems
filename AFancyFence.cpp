//http://codeforces.com/problemset/problem/270/A
#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    while(n--)
    {
        int t;
        cin >> t;
        if(360%(180-t)==0)
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
}
