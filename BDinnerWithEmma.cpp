//http://codeforces.com/problemset/problem/616/B
#include <iostream>
#include <algorithm>
using namespace std;

using ll = long long;

int main()
{
	int m,n;
	cin >> n >> m;
	ll r{0};
	for(int i{0};i<n;i++)
	{
		ll mn{1000000005};
		for(int j{0};j<m;j++)
		{
			ll t;
			cin >> t;
			mn = min(mn,t);
		}
		if(mn>r)
			r = mn;
	}
	cout<<r<<endl;
}
