//http://codeforces.com/problemset/problem/510/A
#include <iostream>
#include <string>
using namespace std;

int main()
{
    int m,n;
    cin >> n >> m;
    string rows[2];
    rows[0] = string(m,'#');
    rows[1] = string(m-1,'.');
    bool left_side{false};
    for(int i{1};i<=n;i++)
    {
        if(i%2!=0)
            cout<<rows[0]<<endl;
        else{
            if(left_side)
                cout<<"#"<<rows[1]<<endl;
            else
                cout<<rows[1]<<"#"<<endl;
            left_side ^= true;
        }
    }
}
