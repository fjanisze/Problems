//http://codeforces.com/gym/100579
#include <iostream>
#include <vector>
#include <map>
#include <cmath>
using namespace std;

using ll = long;
ll k;

constexpr ll size = 10000001;
ll nums[size];
ll primacity[size];

void generate_table()
{
	for(int i{0};i<size;i++)
	{
		nums[i] = i;
	}
	for(int i{2};i<size;i++)
	{
		if(nums[i] == 0 )continue;
		for(int j{i*2};j<size;j+=i)
			nums[j] = 0;
	}
	for(int i{2};i<size;i++)
	{
		if(nums[i]==0) continue;
		for(int j{i};j<size;j+=i){
			++primacity[j];
		}
	}
}

int main()
{
	int t;
	cin >> t;
	int c{1};
	generate_table();
	while(c<=t)
	{
		ll a,b,r{0};
		cin >> a >> b >> k;
		while(a<=b)
		{
			if(primacity[a]==k) ++r;
			++a;
		}
		cout<<"Case #"<<c++<<": "<<r<<endl;
	}
}
