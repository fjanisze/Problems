#include <iostream>
using namespace std;

int gcd(int a, int b)
{
	if(b==0) return a;
	return gcd(b,a%b);
}

int main()
{
	int a,b,s;
	cin >> a >> b >> s;
	while(s>=0)
	{
		int t;
		if((t = gcd(max(a,s),min(a,s)))>s){
			cout<<1<<endl;
			break;
		}
		s -= t;
		if((t = gcd(max(b,s),min(b,s)))>s)
		{
			cout<<0<<endl;
			break;
		}
		s -= t;
	}
}
