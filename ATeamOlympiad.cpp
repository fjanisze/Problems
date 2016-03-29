//http://codeforces.com/problemset/problem/490/A
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n,skill;
    cin >> n;
    vector<int> indexes[3];
    for(int i{0};i<n;i++)
    {
        cin>>skill;
        --skill;
        indexes[skill].push_back(i+1);
    }
    size_t teams{min(indexes[0].size(),
            min(indexes[1].size(),indexes[2].size()))};
    cout<<teams<<endl;
    for(int i{0};i<teams;i++)
    {
        for(int j{0};j<3;j++)
            cout<<indexes[j][i]<<" ";
        cout<<endl;
    }
}
