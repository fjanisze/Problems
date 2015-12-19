#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

using ll = long long;

ll rozpierdol_problem(vector<ll>& d)
{
	ll n{d.size()};
	ll L{0};
	//m contiene l'indice dell'ultimo elemento per una sequenza di lunghezza i
	//p l'indice dell'elemento precedente nella sequenza che compone
	//la massima-subsequenza
	vector<ll> p(n,0),m(n+1,0);
	for(int i{0};i<n;i++)
	{
		ll l{1},r{L};
		while(l<=r)
		{
			ll mid = ceil((l+r)/2);
			if(d[m[mid]]<d[i]){
				l = mid + 1;
			}else{
				r = mid - 1;
			}
		}

		ll nL = l;

		p[i] = m[nL-1];
		m[nL] = i;

		if(nL>L)
		{
			L = nL;
		}
	}
	return L;
}

#include <iostream>
#include <vector>
using namespace std;

int main()
{
	ll n, k;
	cin >> n >> k;
	if( n==1 || k==0 )
	{
		cout<<"1\n";
		return 0;
	}
	vector<ll> d(n);
	for(int i{0};i<n;i++)
		cin >> d[i];
//	rozpierdol_problem(d);
	std::vector<ll> dp(n,0);
	for(int i{0};i<n;i++)
	{
		dp[i] = i;
		for(int j{0};j<i;j++)
		{
			if(d[j]<d[i])
				dp[i] = dp[i] + dp[j];
		}
	}
	cout<<dp[k+1]<<endl;
}
