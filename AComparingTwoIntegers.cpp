//http://codeforces.com/problemset/problem/616/A
#include <iostream>
#include <string>
using namespace std;

int main()
{
	string a,b;
	cin >> a >> b;
	int i{0},j{0};
	while(a[i]=='0') ++i;
	while(b[j]=='0') ++j;
	a.erase(0,i);
	b.erase(0,j);
	char r = '=';
	if( a.size() < b.size())
		r = '<';
	else if( a.size() > b.size())
		r = '>';
	else{
		for(int i{0};i<a.size();i++)
		{
			if(a[i]<b[i]){
				r = '<';
				break;
			}
			else if(a[i] > b[i]){
				r = '>';
				break;
			}
		}
	}
	cout<<r<<endl;
}
