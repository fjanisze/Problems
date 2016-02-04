//http://codeforces.com/problemset/problem/344/A
#include <iostream>
#include <string>
using namespace std;

int main()
{
	cout.sync_with_stdio(false);
	int n,current_magnet;
	cin >> n;
	int last{0},r{0};
	while(n--)
	{
		cin >> current_magnet;
		r += (current_magnet == last) ? 0 : (last=current_magnet,1);
	}
	cout<<r<<endl;
}
