#include <iostream>
using namespace std;

int main()
{
	int n,r{0};
	cin >> n;
	while(n--)
	{
		int p,c;
		cin >> p >> c;
		if(c-p>=2) ++r;
	}
	cout<<r<<endl;
}
