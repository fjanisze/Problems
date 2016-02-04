//http://codeforces.com/problemset/problem/460/A
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int n,m,r{0};
	cin >> n >> m;
	while(n>0)
	{
		++r;
		--n;
		if(r%m==0)
			++n;
	}
	cout<<r<<endl;
}
