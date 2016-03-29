//http://codeforces.com/problemset/problem/584/A
#include <iostream>
using namespace std;

int main()
{
    int n,t;
    cin >> n >> t;
    if(t==10&&n==1){
        cout<<"-1\n";
        return 0;
    }
    if(t==10){
        cout<<"1";
        --n;
        t = 0;
    }
    for(int i{0};i<n;i++)
        cout<<t;
    cout<<endl;
}
