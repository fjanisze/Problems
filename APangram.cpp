//http://codeforces.com/problemset/problem/520/A
#include <iostream>
#include <string>
using namespace std;

constexpr int size{'z'-'a'+1};
bool chars[size];

int main()
{
    string str;
    int n;
    cin >> n;
    cin >> str;
    for(auto e:str)
    {
        chars[tolower(e)-'a']=true;
    }
    for(int i{0};i<size;i++){
        if(!chars[i]){
            cout<<"NO\n";
            return 0;
        }
    }
    cout<<"YES\n";
}
