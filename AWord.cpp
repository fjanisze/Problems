//http://codeforces.com/problemset/problem/59/A
#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>
using namespace std;

int main()
{
    string str;
    char ch;
    int up{0},low{0};
    while(cin.get(ch))
    {
        if(ch=='\n') break;
        if(islower(ch)) ++low;
        else ++up;
        str+=ch;
    }
    if(low==up||low>up)
        transform(str.begin(),str.end(),str.begin(),::tolower);
    else
        transform(str.begin(),str.end(),str.begin(),::toupper);
    cout<<str<<endl;
}
