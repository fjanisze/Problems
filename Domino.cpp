#include <iostream>
using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;
	int r = max(n * m/2, m * n/2);
	cout<<r<<endl;
}
