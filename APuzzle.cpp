#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	int n,m;
	cin >> n >> m;
	vector<int> d(m);
	for(int i{0};i<m;i++)
		cin >> d[i];
	sort(d.begin(),d.end());
	int r{1<<20};
	--n;
	for(int i{0};i+n<m;i++)
	{
		r = min(r, d[i+n]-d[i]);
	}
	cout<<r<<endl;
}
