//http://codeforces.com/problemset/problem/551/A
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    cout.sync_with_stdio(false);
    int n;
    cin>>n;
    vector<long> data(n);
    vector<long> info(2001);
    for(int i{0};i<n;i++)
    {
        cin>>data[i];
        for(int j{0};j<data[i];j++)
            ++info[j];
    }
    for(int i{0};i<n;i++)
    {
        cout<<1+info[data[i]]<<" ";
    }
    cout<<endl;
    return 0;
}
