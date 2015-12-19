#include <iostream>
#include <algorithm>

using namespace std;

using ll = long long;
constexpr ll m{1e9+7};

ll do_op(ll n)
{
	ll c{0};
	for(ll i{2};i<=n;i++)
	{
		if(i%2==0)
			c = ((i * c)%m + 1)%m;
		else 
			c = ((i * c)%m - 1)%m;
	}
	return c;
}

int main()
{
	int n;
	cin >> n;
	string s;
	for(int i{1};i<=n;i++){
		s.push_back(48+i);
	}
	int c{0};
	vector<string> r;
	do{
		bool ok{true};
		for(int i{1};i<=n;i++)
			if(s[i-1]==(i+48)){
				ok = false;
				break;
			}
		if(ok)
		{
			r.push_back(s);
			++c;
		}
	}while(next_permutation(s.begin(),s.end()));
	for(auto e:r)
	{
		cout<<e<<" : ";
		for(int i{0};i<=n-2;i++)
		{
			bool o{true};
			for(int j{0};j<2;j++)
			{
				int w = j%2;
				if(e[j+i]!=j+i+2){
					o = false;
					break;
				}
			}
			if(o){
				cout<<"OK\n";
			}else cout<<"NOK\n";
		}
	}
}
