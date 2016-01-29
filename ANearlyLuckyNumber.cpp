//http://codeforces.com/problemset/problem/110/A
#include <iostream>
using namespace std;

using ll = long long;

int main()
{
	ll n;
	cin >> n;
	string s(std::to_string(n));
	int c{0};
	for(auto e:s)
	{
		if(e=='4' || e=='7')
			++c;
	}
	cout<<((c==4||c==7)?"YES":"NO")<<endl;
}
