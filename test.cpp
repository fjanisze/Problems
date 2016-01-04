#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

using ll = long long;

int main() {
	ll tc,n,m,r{0};
	cin >> tc;
	while(tc--){
		cin >> n >> m;
		vector<ll> a(n);
		for(ll i{0};i<n;i++)
			cin >> a[i];
		ll r{0};
		vector<ll> s(n);
		set<ll> st;
		s[0] = a[0]%m;
		st.insert(s[0]);
        r = max(r,s[0]);
		for(ll i{1};i<n;i++){
			s[i] = (s[i-1] + a[i])%m;
			st.insert(s[i]);
			r = max(s[i],r);
			auto it = st.upper_bound(s[i]);
			ll v{s[i]};
			if(it!=st.end()){
				v = *it;
			}
			r = max((s[i]-v+m)%m,r);
		}
		cout<<max(r,s.back())<<endl;
	}
	return 0;
}



