//http://codeforces.com/problemset/problem/472/A
#include <iostream>
#include <cmath>
using namespace std;

bool is_prime(long n)
{
	if(n<=1) return false;
	if(n<=3) return true;
	if(n%2==0) return false;
	for(long i{3};i<=sqrt(n);i+=2)
	{
		if(n%i==0)
			return false;
	}
	return true;
}

int main()
{
	long n;
	cin >> n;
	for(long i{2};i<n-2;i++)
	{
		if(!is_prime(i) && !is_prime(n-i))
		{
			cout<<i<<" "<<n-i<<endl;
			break;
		}
	}
}
