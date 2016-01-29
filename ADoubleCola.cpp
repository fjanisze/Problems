#include <iostream>
#include <cmath>
using namespace std;

const char* people[] = {
	"Sheldon",
	"Leonard",
	"Penny",
	"Rajesh",
	"Howard"
};

using ll = long long;

int main()
{
	ll n;
	cin >> n;
	if(n<=5)
		cout<<people[n-1]<<endl;
	else{
		ll p{1};
		ll u{0};
		while((u + 5*p) < n){
			u += p*5;
			p*=2;
		}
		if(u==n)
			cout<<people[4]<<endl;
		else
			cout<<people[(n-u)/p]<<endl;

	}
}
