//http://codeforces.com/problemset/problem/443/A
#include <iostream>
#include <map>
#include <cctype>
using namespace std;

int main()
{
    char ch{};
    map<char,int> data;
    int ans{0};
    for(;;)
    {
        cin >> ch;
        if(ch=='}') break;
        if(isalpha(ch))
        {
            if(++data[ch]==1) ++ans;
        }
    }
    cout<<ans<<endl;
}
