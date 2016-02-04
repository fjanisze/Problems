//http://codeforces.com/problemset/problem/69/A
#include <iostream>
using namespace std;

int main()
{
	std::cout.sync_with_stdio(false);
	int n;
	cin >> n;
	int s{0},a,b,c;
	int x{0},y{0},z{0};
	for(int i{0};i<n;i++)
	{
		cin >> a >> b >> c;
		x += a;
		y += b;
		z += c;
	}
	cout<<(x || y || z ?"NO":"YES")<<endl;
}
