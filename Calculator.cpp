//From SRM, topcoder
#include <iostream>
#include <string>
#include <map>
using namespace std;

using ld = long double;

ld transl[4][4] = {
	//inch,yard,mile,feet
	{1,ld(1)/36,ld(1)/63360,ld(1)/12}, //inch
	{36,1,ld(1)/1760,3}, //Yard
	{63360,1760,1,5280},//mile
	{12,ld(1)/3,ld(1)/5280,1} //feet
};

int main()
{
	ld n;
	cin >> n;
	string from,to;
	cin >> from >> to;
	std::map<string,int> m;
	m["\"i\""] = 0;
	m["\"yd\""] = 1;
	m["\"mi\""] = 2;
	m["\"ft\""] = 3;
	cout.precision(16);
	cout<<ld(n*transl[m[from]][m[to]])<<endl;
}
