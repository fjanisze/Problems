//http://codeforces.com/problemset/problem/635/A
#include <iostream>
#include <set>
using namespace std;

int orchestra[100][100];
int ys,xs,n,k;

int main()
{
    cin>>xs>>ys>>n>>k;
    while(n--)
    {
        int x,y;
        cin >> x >> y;
        orchestra[x][y] = 1;
    }
    int res{0};
    for(int x{1};x<=xs;x++)
    {
        for(int y{1};y<=ys;y++)
        {
            for(int xx{x};xx<=xs;xx++)
            {
                for(int yy{y};yy<=ys;yy++)
                {
                    int r{0};
                    for(int x2{x};x2<=xx;x2++)
                        for(int y2{y};y2<=yy;y2++)
                            if(orchestra[x2][y2]>0) ++r;
                    if(r>=k) res++;
                }
            }
        }
    }
    cout<<res<<endl;
}
