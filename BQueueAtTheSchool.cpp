#include <iostream>
#include <string>
using namespace std;

int main()
{
	int n,t;
	cin >> n >> t;
	string q;
	cin >> q;
	for(int c{0};c<t;c++)
	{
		for(int i{1};i<n;i++)
		{
			if(q[i]=='G' && q[i-1]=='B')
			{
				swap(q[i],q[i-1]);
				++i;
			}
		}
	}
	cout<<q<<endl;
}
