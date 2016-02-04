//http://codeforces.com/problemset/problem/500/A
#include <iostream>
using namespace std;

int main()
{
	cout.sync_with_stdio(false);
	int n,dest,t,skip{1};
	cin >> n >> dest;
	--dest;
	bool success{false};
	for(int i{0};i<n;i++)
	{
		cin >> t;
		if(--skip==0)
		{
			if(i==dest){
				success = true;
				break;
			}
			if(i>dest){
				break;
			}
			skip = t;
		}
	}
	if(success)
		cout<<"YES\n";
	else
		cout<<"NO\n";
}
