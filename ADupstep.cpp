//http://codeforces.com/problemset/problem/208/A
#include <iostream>
#include <string>
using namespace std;

int main()
{
	string s;
	cin >> s;
	bool sp{false};
	if(s.size()<3) cout<<s<<endl;
	else{
		for(size_t i{0};i<s.size();)
		{
			if(s[i]!='W' || s[i+1]!='U' || s[i+2]!='B')
			{
				cout<<s[i];
				++i;
				sp = false;
			}
			else{
				if(i>0 && i<s.size() && !sp){
					cout<<' ';
				}
				sp = true;
				i+=3;
			}
		}
		cout<<endl;
	}
}
