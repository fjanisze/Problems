//http://codeforces.com/problemset/problem/439/A
#include <iostream>
using namespace std;

int main()
{
    int n,d;
    cin>>n>>d;
    int time{0},t;
    for(int i{0};i<n;i++){
        cin>>t;
        time+=t+10;
    }
    time-=10;
    if(time>d)
        cout<<"-1\n";
    else{
        cout<<(n-1)*2+(d-time)/5<<endl;
    }
}
