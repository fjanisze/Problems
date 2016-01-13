#include <iostream>
#include <string>
using namespace std;

int main()
{
	int n,r{0};
	cin >> n;
	for(int i{0};i<n;i++)
	{
		string s;
		cin >> s;
		if(s[1]=='+')
			++r;
		else 
			--r;
	}
	cout<<r<<endl;
}
