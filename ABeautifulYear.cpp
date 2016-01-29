//http://codeforces.com/problemset/problem/271/A
#include <iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;
	for(++n;n<=9012;n++)
	{
		int cnt[10]={0,0,0,0,0,0,0,0,0,0};
		int i{0};
		for(int t{n};i<4;i++,t/=10)
		{
			if(++cnt[t%10]>1) break;
		}
		if(i==4){
			cout<<n<<endl;
			break;
		}
	}
}
