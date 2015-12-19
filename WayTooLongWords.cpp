#include <iostream>
#include <string>
using namespace std;

int main()
{
	int n;
	cin >> n;
	string s;
	for(int i{0};i<n;i++)
	{
		cin >> s;
		if(s.size()>10)
		{
			s = s[0] + to_string(s.size()-2) + s.back();
		}
		cout<<s<<endl;
	}
	return 0;
}
