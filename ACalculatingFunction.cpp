//http://codeforces.com/problemset/problem/486/A
#include <iostream>
using namespace std;


int main()
{
	long long n;
	cin >> n;
	if(n%2==0)
	{
		cout<<n/2<<endl;
	}
	else{
		cout<<-(n/2+1)<<endl;
	}
}
