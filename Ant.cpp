#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

using ll = long long;

//int dt[15][15];

int main()
{
	int n;
	cin >> n;
	vector<pair<ll,ll>> bar;

	for(int i{0};i<n;i++)
	{
		ll x,y,d;
		cin >> x >> y >> d;
//		for(int i{0};i<=d;i++)
//			dt[x+i][y] = 1;
		d += x;
		bar.push_back(make_pair(x,d));
	}
/*	for(int i{1};i<15;i++)
	{
		for(int j{0};j<15;j++)
			cout<<dt[j][i]<<",";
		cout<<endl;
	}*/
	sort(bar.begin(),bar.end());
	ll e = bar[0].second,r{0},b=bar[0].first;
	for(int i{1};i<bar.size();i++)
	{
		if(bar[i].first <= e)
		{
			e = max(e,bar[i].second);
		}
		else
		{
			r += (e-b+1);
			b = bar[i].first;
			e = bar[i].second;
		}
	}
//	cout<<"%"<<r<<" , "<<b<<","<<e<<endl;
	cout<<r+(e-b+1)<<endl;
}
