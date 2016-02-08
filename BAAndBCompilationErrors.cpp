//http://codeforces.com/problemset/problem/519/B
#include <map>
#include <iostream>
using namespace std;

using ll = long long;

int main()
{
	int n;
	ll t;
	cin >> n;
	map<ll,int> data;
	for(int i{0};i<n;i++)
	{
		cin >> t;
		++data[t];
	}
	ll sol[2] = {0,0};
	for(int j{1};j<=2;j++)
	{
		map<ll,int> cur_data;
		for(int i{0};i<n-j;i++)
		{
			cin >> t;
			++cur_data[t];
		}
		for(auto& elem:data)
		{
			if(cur_data[elem.first]!=elem.second)
			{
				sol[j-1] = elem.first;
				break;
			}
		}
		data = cur_data;
	}
	cout<<sol[0]<<endl;
	cout<<sol[1]<<endl;
}
