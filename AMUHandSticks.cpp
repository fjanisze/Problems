//http://codeforces.com/problemset/problem/471/A
#include <iostream>
#include <map>
using namespace std;

int main()
{
    int temp,cur{0};
    map<int,int> sticks;
    for(int i{0};i<6;i++)
    {
        cin>>temp;
        ++sticks[temp];
    }
    bool legs{false},bear{false};
    for(auto e:sticks)
    {
        if(e.second>=4)
            legs=true;
        else if(e.second==1)
            bear=true;
    }
    if(!legs)
        cout<<"Alien\n";
    else
        cout<<(bear?"Bear":"Elephant")<<endl;
}
