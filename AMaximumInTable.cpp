//http://codeforces.com/problemset/problem/509/A
#include <iostream>
using namespace std;

//int table[10][10];

int table[10]={1,2,6,20,70,252,924,3432,12870,48620};

int main()
{
   /* for(int i{0};i<10;i++)
    {
        table[0][i] = 1;
        table[i][0] = 1;
    }
    for(int i{1};i<10;i++)
    {
        for(int j{1};j<10;j++)
        {
            table[i][j]=table[i-1][j]+table[i][j-1];
            if(i==j) cout<<table[i][j]<<",";
        }
    }*/
    int n;
    cin >> n;
    cout<<table[n-1]<<endl;
}
