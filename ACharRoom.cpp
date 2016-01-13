#include <iostream>
#include <string>
using namespace std;

int main()
{
	char p[] = {"hello"};
	int j{0};
	string s;
	cin >> s;
	for(int i{0};i<s.size();i++)
	{
		if(j<5 && s[i]==p[j]) ++j;
	}
	if(j>=5)
	{
		cout<<"YES\n";
	}
	else{
		cout<<"NO\n";
	}
}
