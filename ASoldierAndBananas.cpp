//http://codeforces.com/problemset/problem/546/A
#include <iostream>
using namespace std;

int main()
{
	long long k,n,w;
	cin >> k >> n >> w;
	cout<<max((long long)0,(w*(w+1)/2)*k-n)<<endl;
}
