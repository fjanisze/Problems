//http://codeforces.com/problemset/problem/478/A
#include <iostream>
using namespace std;

int main()
{
    int sm{0};
    for(int i{0};i<5;i++)
    {
        int t;
        cin >> t;
        sm += t;
    }
    if(sm%5!=0 || sm==0) cout<<"-1\n";
    else cout<<sm/5<<endl;
}
