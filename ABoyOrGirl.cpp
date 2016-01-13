#include <iostream>
#include <string>
#include <set>
using namespace std;

int main()
{
	string s;
	cin >> s;
	set<char> chs;
	for(auto e:s)
		chs.insert(e);
	if(chs.size()%2==0)
		cout<<"CHAT WITH HER!\n";
	else
		cout<<"IGNORE HIM!\n";
	return 0;
}
