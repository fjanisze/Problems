#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int a,b;
	cin >> a >> b;
	int r{0},c{0};
	while(a>0)
	{
		r += a;
		c += a;
		a = floor(c/b);
		if(a*b > 0)
			c %= a*b;
		else c = 0;
	}
	cout<<r<<endl;
	return 0;
}
