//http://codeforces.com/problemset/problem/580/A
#include <iostream>
#include <cstdio>
using namespace std;

using ll = long long;

int main()
{
	std::cout.sync_with_stdio(false);
	ll n,p{0},c{0},r{0},t;
	cin >> n;
	for(int i{0};i<n;i++)
	{
		cin >> t;
		if(t>=p)
			++c;
		else r=max(r,c),c=1;
		p = t;
	}
	cout<<max(r,c)<<endl;
}
