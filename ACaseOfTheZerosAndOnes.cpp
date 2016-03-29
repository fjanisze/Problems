//http://codeforces.com/problemset/problem/556/A
#include <iostream>
#include <stack>
using namespace std;

int main()
{
    int n;
    cin >> n;
    stack<bool> bits;
    char ch;
    bool current;
    for(int i{0};i<n;i++)
    {
        cin>>ch;
        current=(ch=='1');
        if(!bits.empty()&&bits.top()!=current)
        {
            bits.pop();
        }
        else{
            bits.push(current);
        }
    }
    cout<<bits.size()<<endl;
}
