#include <iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;
	int c{0},r{0};
	while(n--)
	{
		int a,b;
		cin >> a >> b;
		c += (b - a);
		r = max(r,c);
	}
	cout<<r<<endl;
}
