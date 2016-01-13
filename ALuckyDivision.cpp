#include <iostream>
using namespace std;

int tbl[] = {4,7,44,47,74,77,444,447,474,477,744,747,774,777};

int main()
{
	int n;
	cin >> n;
	bool ok{false};
	for(int i{0};i<(sizeof(tbl)/sizeof(int));i++)
	{
		if(n == tbl[i])
		{
			ok = true;
			break;
		}
		else if(n%tbl[i]==0){
			ok = true;
			break;
		}
	}
	if(ok)
		cout<<"YES\n";
	else 
		cout<<"NO\n";
}
