#include <iostream>
using namespace std;

int main()
{
	int n,r{0};
	cin >> n;
	while(n--)
	{
		int a,b,c;
		cin >> a >> b >> c;
		if(a+b+c>=2)
			++r;
	}
	cout<<r<<endl;
}


