#include <iostream>
#include <string>
using namespace std;

int main()
{
	string s;
	int r{0};
	while(!cin.eof())
	{
		char ch;
		cin >> ch;
		if(!s.empty()){
			if(ch == s.back())
			{
				++r;
				if(r>=7){
					cout<<"YES\n";
					return 0;
				}
			}
			else 
				r = 1;
		}
		else ++r;
		s += ch;
	}
	cout<<"NO\n";
	return 0;
}
