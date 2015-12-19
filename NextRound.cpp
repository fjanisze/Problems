#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n,k;
	cin >> n >> k;
	vector<int> d(n);
	int c{0};
	for(int i{0};i<n;i++)
	{
		cin >> d[i];
	}
	for(int i{0};i<n;i++)
	{
		if(d[i]>0 && d[i]>=d[k-1]) ++c;
	}
	cout<<c<<endl;
}
