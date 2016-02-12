//http://codeforces.com/contest/622/problem/C
#include <iostream>
#include <vector>
using namespace std;

constexpr int size{1000001};

struct map_t
{
    int i;
    int n;
    int c;
    map_t():n{0},c{0},i{0}{}
}map[size];

int mapping[size];

int main()
{
    //cout.sync_with_stdio(false);
    int n,m;
    scanf("%d %d",&n,&m);
    int c{1},t;
    cin >> t;
    map[c].n = t;
    map[c].c = 1;
    map[c].i = 1;
    mapping[1] = 1;
    for(int i{2};i<=n;i++)
    {
        scanf("%d",&t);
        if(map[c].n!=t)
        {
            ++c;
            map[c].n = t;
            map[c].i = i;
        }
        ++map[c].c;
        mapping[i] = c;
    }
    c = 1;
    int l,r,x;
    vector<int> ans(m);
    for(int i{0};i<m;i++)
    {
        scanf("%d %d %d",&l,&r,&x);
        int p = mapping[l];
        while(map[p].n==x && map[p].i<r && map[p].i!=0)
        {
            ++p;
        }
        ans[i] = ((map[p].i>r||map[p].i==0||map[p].n==x)?-1:max(l,map[p].i));
    }
    for(auto e:ans)
        printf("%d\n",e);
}
