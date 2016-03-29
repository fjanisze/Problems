//http://codeforces.com/problemset/problem/327/A
#include <iostream>
using namespace std;

int table[101];
int main()
{
    int n,t,num_of_ones{0};
    cin >> n;
    for(int i{1};i<=n;i++){
        cin>>t;
        num_of_ones+=(t==1);
        table[i]=(t==1?-1:1);
    }
    int cur{0},ans{0};
    for(int i{1};i<=n;i++){
        cur=max(0,cur+table[i]);
        ans=max(cur,ans);
    }
    if(ans==0) --ans;
    cout<<num_of_ones+ans<<endl;
}
