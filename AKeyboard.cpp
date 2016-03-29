//http://codeforces.com/problemset/problem/474/A
#include <iostream>
#include <string>
using namespace std;

string keyboard = {"qwertyuiopasdfghjkl;zxcvbnm,./"};

int main()
{
    char pos;
    cin >> pos;
    string str;
    cin >> str;
    for(int i{0};i<str.size();i++)
    {
        for(int j{0};j<keyboard.size();j++)
        {
            if(keyboard[j]==str[i]){
                cout<<keyboard[j+(pos=='R'?-1:+1)];
            }
        }
    }
    cout<<endl;
}
