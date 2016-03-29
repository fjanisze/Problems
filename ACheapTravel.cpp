//http://codeforces.com/problemset/problem/466/A
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n,m,a,b;
    cin>>n>>m>>a>>b;
    cout<<min(n*a,min((n/m)*b+(n%m)*a,(1+n/m)*b))<<endl;
}
