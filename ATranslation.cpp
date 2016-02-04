#include <iostream>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	string a,b;
	cin >> a >> b;
	std::reverse(a.begin(),a.end());
	if(a==b)
		cout<<"YES\n";
	else
		cout<<"NO\n";
}
