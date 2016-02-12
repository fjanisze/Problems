//http://codeforces.com/contest/622/problem/B
#include <iostream>
#include <string>
using namespace std;

constexpr int ti(char ch)
{
    return ch-'0';
}

int main()
{
    string s;
    cin >> s;
    int hh = ti(s[0])*10+ti(s[1]);
    int mm = ti(s[3])*10+ti(s[4]);
    int tmin = hh*60+mm;
    int a;
    cin >> a;
    tmin += a;
    tmin %= 1440;
    hh = tmin/60;
    mm = tmin%60;
    cout<<((hh<10)?"0":"")<<hh<<":"<<((mm<10)?"0":"")<<mm<<endl;
}
