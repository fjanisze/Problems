//http://codeforces.com/problemset/problem/448/A
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int medals{0},cups{0},t;
    for(int i{0};i<6;i++)
    {
        cin >> t;
        if(i<3)
            cups+=t;
        else
            medals+=t;
    }
    int n;
    cin >> n;
    if(medals%10==0) n-=medals/10;
    else n-=(1+medals/10);
    if(cups%5==0) n-=cups/5;
    else n-=(1+cups/5);
    if(n<0) cout<<"NO\n";
    else cout<<"YES\n";
}
