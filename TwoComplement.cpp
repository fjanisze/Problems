#include <iostream>
#include <vector>
#include <iterator>
#include <cmath>
#include <limits>
using namespace std;

using ll = long long;
constexpr long mx = 2147483647;

int bit_count(long i)
{
     i = i - ((i >> 1) & 0x55555555);
     i = (i & 0x33333333) + ((i >> 2) & 0x33333333);
     return (((i + (i >> 4)) & 0x0F0F0F0F) * 0x01010101) >> 24;
}

ll brute_force(long a,long b)
{
	ll ans{0};
	while(a<=b)
	{
		ans += bit_count(a);
		++a;
	}
	return ans;
}

ll mpow(long n,long p)
{
	if(p<0) return 0;
	ll r{1};
	while(p-->0) r*=n;
	return r;
}

long calc_positive(long n)
{
	if(n==1) return 1;
	if(n<=0) return 0;
	long x = log2(n);
	long p = mpow(2,x-1);
	return x*p + calc_positive(n-p*2) + (n-p*2+1);
}

long calc_negative(long n)
{
	return (calc_positive(mx) - calc_positive(mx - abs(n))+ abs(n));
}

int main()
{
	long n;
	ll ans{0};
	cin >> n;
	n*=2;
	vector<long> data(n);
	for(long i{0};i<n;i++)
		cin>>data[i];
	if(data.size()%2!=0)
	{
		cerr<<"This is not good!\n";
	}
	else
	{
		for(ll i{0};i<data.size();i+=2)
		{
			long a = data[i];
			long b = data[i+1];
			if(a>=0 && b>=0)
			{
				cout<<(calc_positive(b)-calc_positive(a-1))<<","<<brute_force(a,b)<<endl;
			}
			else if(a<=0 && b<0)
			{
				cout<<calc_negative(a) - calc_negative(b+1)<<","<<brute_force(a,b)<<endl;
			}
			else if(a<0 && b>=0)
			{
				cout<<calc_negative(a) + calc_positive(b)<<","<<brute_force(a,b)<<endl;
			}
		}
	}
	return 0;
}
