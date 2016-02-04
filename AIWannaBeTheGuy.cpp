//http://codeforces.com/problemset/problem/469/A
#include <iostream>
using namespace std;

int data[101];

int main()
{
	cout.sync_with_stdio(false);
	int n,t;
	cin >> n;
	int p,r{0};
	for(int i{0};i<2;i++)
	{
		cin >> p;
		for(int i{0};i<p;i++)
		{
			cin >> t;
			r += (data[t]==0);
			data[t] = 1;
		}
	}
	if(r!=n)
		cout<<"Oh, my keyboard!\n";
	else
		cout<<"I become the guy.\n";
}

