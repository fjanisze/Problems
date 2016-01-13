#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>
using namespace std;

int main()
{
	string s;
	cin >> s;
	string c = s;
	int n{0};
	string l = s;
	transform(s.begin(),s.end(),c.begin(),::toupper);
	transform(s.begin(),s.end(),l.begin(),::tolower);
	for(int i{0};i<s.size();i++)
	{
		if(s[i]==c[i])
			++n;
	}
	if(n==s.size())
		cout<<l<<endl;
	else if(s[0]==l[0] && n==s.size()-1)
	{
		cout<<c[0]<<l.substr(1,l.size()-1)<<endl;
	}
	else
		cout<<s<<endl;
}
