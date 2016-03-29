//http://codeforces.com/contest/630/problem/C
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int n;
    cin >> n;
    long long r{0};
    for(int i{1};i<=n;i++)
        r+=pow(2,i);
    cout<<r<<endl;
}
