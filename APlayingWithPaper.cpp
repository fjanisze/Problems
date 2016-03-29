//http://codeforces.com/problemset/problem/527/A
#include <iostream>
using namespace std;

using ll=long long;

int main()
{
    ll a,b,ans{1};
    cin>>a>>b;
    ll s{a},s2{b};
    a=max(a,b);
    b=min(a,b);
    while(b>0&&a!=b){
        ans += a/b;
        s=a;
        a=b;
        b=s%b;
    }
    cout<<ans-1<<endl;
}

