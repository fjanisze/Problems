#include <iostream>
using namespace std;


int main()
{
	int w;
	cin >> w;
	if(w<=2){
		cout<<"NO\n";
	}else if(w%2==0){
		cout<<"YES\n";
	}else{
		for(int i{2};i<=w;i++)
		{
			if((w-i)%2==0 && (i%2)==0){
				cout<<"YES\n";
				return 0;
			}
		}
		cout<<"NO\n";
	}
	return 0;
}
