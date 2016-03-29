//http://codeforces.com/problemset/problem/405/A
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> d(n);
    for(int i{0};i<n;i++)
        cin>>d[i];
    sort(d.begin(),d.end());
    for(auto e:d)
        cout<<e<<" ";
    cout<<endl;
}
