#include <iostream>
#include <string>
using namespace std;

int main()
{
	int r{0},n;
	string s;
	cin >> n >> s;
	if(s.size()>1)
	{
		for(int i{1};i<s.size();i++)
		{
			if(s[i]==s[i-1]) ++r;
		}
	}
	cout<<r<<endl;
}
