//http://codeforces.com/problemset/problem/514/A
#include <iostream>
using namespace std;

int main()
{
    char ch;
    int c{0};
    while(cin.get(ch))
    {
        if(ch=='\n') break;
        ch -='0';
        if(ch>(9-ch) && (c>0||ch!=9))
                cout<<9-ch;
        else
            cout<<(int)ch;
        ++c;
    }
    cout<<endl;
}
