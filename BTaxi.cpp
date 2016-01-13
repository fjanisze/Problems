#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<int> d(n);
	for(int i{0};i<n;i++)
		cin >> d[i];
	sort(d.rbegin(),d.rend());
	int r{0};
	n = 0;
	int j{d.size()-1};
	for(int i{0};i<=j;i++)
	{
		n = d[i];
		++r;
		for(;j>i;)
		{
			if(n + d[j] > 4)
				break;
			else{
				n += d[j];
				--j;
			}
		}
		cout<<endl;
	}
	cout<<r<<endl;
}

