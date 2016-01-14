#include <iostream>
#include <string>
using namespace std;

int days[] = {31,29,31,30,31,30,31,31,30,31,30,31};
int last_week = 6;

int main()
{
	int n,r{0};
	cin >> n;
	string t;
	cin >> t >> t;
	if(t.find("week")!=string::npos)
	{
		r = 52 + (( n == 5 || n == 6)?1:0);
	}else{
		for(int i{0};i<sizeof(days)/sizeof(int);i++)
		{
			if(n<=days[i]) ++r;
		}
	}
	cout<<r<<endl;
}
