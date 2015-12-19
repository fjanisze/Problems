#include <iostream>
#include <array>
#include <vector>
#include <stack>
#include <set>
#include <algorithm>
#include <array>
using namespace std;

constexpr int tb_size{45};
using ll = unsigned long long;
array<array<ll,tb_size>,tb_size> coef;

void build_coef(int px,int py)
{
	if(px>=tb_size) return;
	coef[py][0] = 1;
	for(ll x{1};x<px;x++){
		coef[py][x] = coef[py-1][x]+coef[py-1][x-1];
	}
	coef[px][px] = 1;
	build_coef(px+1,py+1);
}

vector<ll> im;

ll brutus(ll n, ll j, ll k)
{
    if(n==0) return 0;
    if(k>=im.size()) return 0;
    ll rem{0};
    for(ll i{im[k]+1};i<=n;i++){
        ll n1 = n - i;
        ll j1 = j -1;
        rem += coef[n1 + j1 - 1][n1];
    }
    return rem + brutus(n-im[k],j-1 ,k+1);
}

ll do_the_math(ll n,ll j){
	ll r{0};
    for(ll i{0};i<=n;i++){
		r += coef[i+j-1][i];
	}
    ll rem = brutus(n,j,0);
    return r - rem;
}


int main()
{
    int tc{1};
    build_coef(0,0);
    while(cin){
	int n;
        cin >> n;
        if(n==0) break;
        long s{0};
        im.clear();
        long d{0};
        for(int i{0};i<n;i++)
        {
            long v;
            cin >> v;
            s+=v;
            if(v==0) ++d;
            im.push_back(v);
        }
	    ll r = do_the_math(s,n-d);
        cout<<"Case "<<tc++<<": "<<r<<endl;
	}
}


