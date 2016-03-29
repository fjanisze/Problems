//http://codeforces.com/problemset/problem/25/A
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> d(n);
    int odd{0},even{0};
    int last_even{0},last_odd{0};
    for(int i{0};i<n;i++)
    {
        cin>>d[i];
        if(d[i]%2)
            ++odd,last_odd=i;
        else
            ++even,last_even=i;
        if(even&&odd&&(even>1||odd>1)){
            cout<<(even>1?last_odd:last_even)+1<<endl;
            break;
        }
    }
}
