//https://www.hackerearth.com/problem/algorithm/number-of-divisors-5/
#include <iostream>
#include <map>
#include <cmath>
#include <vector>
using namespace std;

using ll = long long;

int main()
{
	std::ios::sync_with_stdio(false);
	ll n;
	cin >> n;
	while(n--)
	{
		ll k;
		cin >> k;
		map<ll,ll> factors;
		while(k%2==0)
			++factors[2], k/=2;
		for(ll p{3};p<=sqrt(k);p+=2)
		{
			while(k%p==0)
				++factors[p], k/=p;
		}
		if(k>2)
			++factors[k];
		ll r{1};
		for(auto e:factors)
			r*=(e.second+1);
		cout<<r<<endl;
	}
}
