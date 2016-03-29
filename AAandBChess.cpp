//http://codeforces.com/problemset/problem/519/A
#include <iostream>
#include <map>
using namespace std;

map<char,int> weight;

int main()
{
    weight['q']=9;
    weight['r']=5;
    weight['b']=3;
    weight['n']=3;
    weight['p']=1;
    weight['k']=0;

    char ch;
    int white{0},black{0};
    for(int i{0};i<8;i++)
    {
        for(int j{0};j<8;j++)
        {
            cin >> ch;
            if(ch=='.') continue;
            if(islower(ch))
                black+=weight[ch];
            else
                white+=weight[tolower(ch)];
        }
    }
    if(white>black) cout<<"White\n";
    else if(white<black) cout<<"Black\n";
    else cout<<"Draw\n";
}
