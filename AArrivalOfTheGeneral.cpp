//http://codeforces.com/problemset/problem/144/A
#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int mx{0},mn{0};
	int n;
	cin >> n;
	vector<int> d(n);
	for(int i{0};i<n;i++)
	{
		cin >> d[i];
		if(d[i]>d[mx])
			mx = i;
		if(d[i]<=d[mn])
			mn = i;
	}
	cout<<(mx+(n-mn-1)-(mx>mn))<<endl;
}
