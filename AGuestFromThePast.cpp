//http://codeforces.com/contest/625/problem/0
#include <iostream>
using namespace std;

int main()
{
    long long n , a , b , c;
    cin >> n >> a >> b >> c;
    if( a <= b-c || n < b )
        cout << n/a << endl;
    else
        cout << (n-c)/(b-c)+(n-(n-c)/(b-c)*(b-c))/a << endl;
    return 0;
}
