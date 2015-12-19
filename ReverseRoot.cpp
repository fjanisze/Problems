#include <iostream>
#include <cmath>
#include <vector>
#include <iterator>
#include <algorithm>
#include <iomanip>
using namespace std;

using ll = long long;

int main()
{
	vector<ll> data(std::istream_iterator<ll>(std::cin),
			std::istream_iterator<ll>());
	reverse(data.begin(),data.end());
	for(auto e:data)
	{
		cout<<std::setprecision(16)<<double(sqrt(e))<<endl;
	}
}

