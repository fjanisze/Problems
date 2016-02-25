//http://codeforces.com/problemset/problem/630/L
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

constexpr int to_int(const char ch)
{
    return ch-'0';
}

int main()
{
    string number;
    cin >> number;
    long long n = to_int(number[0])*10000+to_int(number[2])*1000+
        to_int(number[4])*100+to_int(number[3])*10+to_int(number[1]);
    long long ans{n};
    for(int i{0};i<4;i++)
    {
        ans *= n;
        ans %= 100000;
    }
    cout<<setfill('0')<<setw(5)<<ans<<endl;
}
