#include <iostream>
#include <bitset>
#include <cmath>
using namespace std;

using ll = long long;

int main()
{
	ll a,b,r{0};
	cin >> a >> b;
	bitset<64> b_a(a);
	bitset<64> b_b(b);
	ll p{1};
	while(log2(p)<=(log2(b)+1))
	{
		bitset<64> pattern(p);
		for(int i{0},c{pattern.count()-1};i<c;i++)
		{
			if(i>0) pattern[i-1] = 1;
			pattern[i] = 0;
			if(pattern.to_ullong() >= a &&
				pattern.to_ullong() <= b)
			{
			//	cout<<pattern.to_string()<<" "<<pattern.to_ullong()<<endl;
				++r;
			}
		}
		p <<= 1;
		p |= 1;
	}
	cout<<r<<endl;
}
