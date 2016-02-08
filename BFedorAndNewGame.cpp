//http://codeforces.com/problemset/problem/467/B
#include <iostream>
#include <vector>
using namespace std;

int main()
{
	long n,m,k;
	cin >> n >> m >> k;
	vector<long> d(m);
	for(int i{0};i<m;i++)
	{
		cin >> d[i];
	}
	long fedor,ans{0};
	cin >> fedor;
	for(int i{0};i<m;i++)
	{
		long mask = 1,c{0};
		for(int j{0};j<n;j++)
		{
			if((mask&fedor)^(mask&d[i]))
			{
				++c;
			}
			mask<<=1;
		}
		if(c<=k)
			++ans;
	}
	cout<<ans<<endl;
}
