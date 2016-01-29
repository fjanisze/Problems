//http://codeforces.com/problemset/problem/263/A
#include <iostream>
using namespace std;

int matrix[5][5];

int main()
{
	int r{0};
	for(int i{1};i<=5;i++)
	{
		for(int j{1};j<=5;j++)
		{
			int t;
			cin >> t;
			if(t==1)
			{
				r = abs(i-3)+abs(j-3);
			}
		}
	}
	cout<<r<<endl;
}
