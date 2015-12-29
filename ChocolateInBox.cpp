//Game of nim, from hackerrank
#include <iostream>
#include <vector>
using namespace std;

using ll = long long;


int main()
{
	int n;
	cin >> n;
	vector<ll> data(n);
	ll nim_sum{0};
	for(int i{0};i<n;i++)
	{
		cin >> data[i];
		nim_sum ^= data[i];
	}
	if(nim_sum==0){
		//No way to win this game
		cout<<0<<endl;
	}
	else{
		int r{0};
		for(int i{0};i<n;i++)
		{
			if(data[i]>(nim_sum^data[i]))
					++r;
		}
		cout<<r<<endl;
	}
	return 0;
}
