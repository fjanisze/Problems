//http://codeforces.com/problemset/problem/148/A/

#include <iostream>
using namespace std;

bool hit[100000];

int main()
{
	int k,l,m,n,d;
	cin >> k >> l >> m >> n >> d;
	int r{0};
	for(int i{1};i<=d;i++)
	{
		if(i%k==0 || i%l==0 || i%m==0 || i%n==0){
			if(hit[i]==false){
				++r;
				hit[i] = true;
			}
		}
	}
	cout<<r<<endl;
}

