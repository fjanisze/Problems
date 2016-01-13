#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<int> c(n,0);
	int s{0};
	for(int i{0};i<n;i++)
	{
		cin >> c[i];
		s += c[i];
	}
	sort(c.rbegin(),c.rend());
	int r{0},m{0};
	while(m<=s)
	{
		s -= c[r];
		m += c[r++];
	}
	cout<<r<<endl;
}
