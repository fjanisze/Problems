//http://codeforces.com/problemset/problem/492/B
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <iomanip>
using namespace std;

using ll = long long;
vector<ll> d;
ll le;

bool solve(long double val)
{
	for(ll i{1};i<d.size();i++)
	{
		if((d[i]-d[i-1])>val)
			return true;
	}
	return false;
}

int main()
{
	cout.sync_with_stdio(false);
	ll n,t;
	cin >> n >> le;
	set<ll> data;
	for(ll i{0};i<n;i++)
	{
		cin >> t;
		data.insert(t);
	}
	d.reserve(data.size());
	for(auto e:data)
	{
		d.push_back(e);
	}
	if(d[0]!=0)
		d.insert(d.begin(),-d[0]);
	if(d.back()!=le)
		d.push_back(le+(le-d.back()));
	long double l{0}, r{2*1e9+1};
	while((r-l)>0.0000000002)
	{
		long double m = (l+r)/2;
	//	cout<<setprecision(32)<<l<<","<<r<<","<<m<<","<<r-l<<endl;
		//cin >> t;
		if(solve(m))
			l = m;
		else
			r = m;
	}
	cout<<setprecision(10)<<r/2<<endl;
}
