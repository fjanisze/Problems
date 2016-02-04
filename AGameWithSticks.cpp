#include <iostream>
using namespace std;

const char* a[2] = {"Akshat", "Malvika"};

int main()
{
	int n,m;
	cin >> n >> m;
	cout<<a[min(n,m)%2==0]<<endl;

}
