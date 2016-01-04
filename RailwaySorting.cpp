//Problem C. Sorting Railway Cars from codeforces
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int n,c{1},r{1},t;
	cin >> n;
	vector<int> p(n+1);
	for(int i{0};i<n;i++)
	{
		cin >> t;
		p[t] = i;
	}
	for(int i{2};i<=n;i++)
	{
		if(p[i] > p[i-1]){
			++c;
		}else{
			r = max( r, c );
			c = 1;
		}
	}
	cout<<n-max(r,c)<<endl;
}
