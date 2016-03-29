//http://codeforces.com/problemset/problem/583/A
#include <iostream>
using namespace std;

bool roads[50][2];

int main()
{
    int n;
    cin>>n;
    int hor,ver,intersection{1};
    for(int i{0};i<n*n;i++)
    {
        cin>>hor>>ver;
        if(roads[hor-1][0]||roads[ver-1][1]){
            ++intersection;
        }else{
            cout<<intersection++<<endl;
            roads[hor-1][0]=roads[ver-1][1]=true;
        }
    }
}
