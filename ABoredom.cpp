//http://codeforces.com/problemset/problem/455/A
#include <iostream>
#include <vector>
using namespace std;

using ll = long long;

ll data[100005];
ll ans[100005];

int main()
{
    ll n,t;
    cin>>n;
    for(ll i{0};i<n;i++)
    {
        cin>>t;
        ++data[t];
    }
    ans[0]=0;
    ans[1]=data[1];
    for(ll i{2};i<=100000;i++)
    {
        ans[i]=max(ans[i-1],ans[i-2]+data[i]*i);
    }
    cout<<ans[100000]<<endl;
}
