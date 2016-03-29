//http://codeforces.com/contest/651/problem/0
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int a,b;
    cin >> a >> b;
    int p = max(a,b);
    int c = min(a,b);
    int ans{0};
    if(p>1){
    do{
        ++ans;
        if(p<=2){
            swap(p,c);
        }
        p-=2;
        c++;
    }while(p>0 && c>0);
    }
    cout<<ans<<endl;
}
