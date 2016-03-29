//http://codeforces.com/problemset/problem/567/A
#include <iostream>
#include <vector>
#include <iostream>
using namespace std;

using ll = long long;

int main()
{
    cout.sync_with_stdio(false);
    int n;
    cin >> n;
    vector<ll> data(n);
    ll mn{1000000001},mx{-1000000001};
    for(int i{0};i<n;i++){
        cin>>data[i];
        mn=min(mn,data[i]);
        mx=max(mx,data[i]);
    }
    cout<<abs(data[0]-data[1])<<" "<<abs(data[0]-mx)<<endl;
    for(int i{1};i<n-1;i++)
    {
        cout<<min(abs(data[i-1]-data[i]),abs(data[i+1]-data[i]))<<" ";
        cout<<max(abs(data[i]-mn),abs(data[i]-mx))<<endl;
    }
    cout<<abs(data[n-1]-data[n-2])<<" "<<abs(data[n-1]-mn)<<endl;
}
