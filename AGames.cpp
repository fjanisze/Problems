//http://codeforces.com/problemset/problem/268/A
#include <iostream>
#include <vector>
using namespace std;

struct uniform
{
	int h,g;
};

int main()
{
	int n,r{0};
	cin >> n;
	vector<uniform> data(n);
	for(int i{0};i<n;i++)
		cin >> data[i].h >> data[i].g;
	for(int i{0};i<n;i++)
	{
		for(int j{0};j<n;j++)
		{
			if(i==j) continue;
			if(data[i].h == data[j].g) 
				++r;
		}
	}
	cout<<r<<endl;
}
