//http://codeforces.com/problemset/problem/479/A
#include <iostream>
using namespace std;

int main()
{
	int a,b,c;
	cin >> a >> b >> c;
	int r{a*b*c};
	r = max(r, (a+b)*c);
	r = max(r, a*(b+c));
	r = max(r, a+b+c);
	cout<<r<<endl;
}
