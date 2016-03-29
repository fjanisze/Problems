//http://codeforces.com/problemset/problem/432/A
#include <iostream>
using namespace std;

int main()
{
    int n,k,num_of_partecipents{0},temp;
    cin>>n>>k;
    for(int i{0};i<n;i++)
    {
        cin>>temp;
        if(5-temp>=k) ++num_of_partecipents;
    }
    cout<<num_of_partecipents/3<<endl;
}
