//http://codeforces.com/contest/651/problem/B
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> data(n);
    for(int i{0};i<n;i++)
        cin >> data[i];
    sort(data.begin(),data.end());
    int ans{0};
    for(int i{0};i<n;i++)
    {
        int c{data[i]};
        if(c==0) continue;
        for(int j{i+1};j<n;j++)
            if(data[j]>c){
                ++ans;
                c = data[j];
                data[j] = 0;
            }
    }
    cout<<ans<<endl;
}
