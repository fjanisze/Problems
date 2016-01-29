//http://codeforces.com/problemset/problem/136/A
#include <iostream>
using namespace std;

int cnt[101];

int main()
{
	int n;
	cin >> n;
	for(int i{1};i<=n;i++)
	{
		int t;
		cin >> t;
		cnt[t] = i;
	}
	for(int i{1};i<=n;i++)
		cout<<cnt[i]<<" ";
	cout<<endl;
}
