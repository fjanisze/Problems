//http://codeforces.com/problemset/problem/476/A
#include <iostream>
using namespace std;

int main()
{
    int n,m;
    cin>>n>>m;
    if(m>n){
        cout<<"-1\n";
    }
    else{
        int ans{n/2+(n%2!=0)};
        while(ans%m!=0)
        {
            ++ans;
        }
        cout<<ans<<endl;
    }
}
