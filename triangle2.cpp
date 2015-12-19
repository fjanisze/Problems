#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;

using ll = long long;

namespace{
	constexpr ll inv{9999};
	ll N;
	vector<ll> pw;
	vector<ll> A;
}

ll binary(vector<ll>& data, ll v, ll l,ll r)
{
	while(l<r)
	{
		int m = (l+r)/2;
		if(data[m]==v) return m;
		if(data[m] > v ) r=m-1;
		else l=m+1;
	}
	return l;
}
int main(){
	int N;
	cin >> N;
	A.reserve(N);
	pw.reserve(N);
	for(int A_i = 0;A_i < N;A_i++){
		cin >> A[A_i];
		pw[A_i] = A[A_i] * A[A_i];
	}
	ll res[3] = {0,0,0};
	// your code goes here
	for(int i{0};i<N;i++){
		int j,k;
		for(j=i+1;j<N;j++){
			ll l = binary(pw,pw[i]+pw[j],j+1,N);
			for(;k<=l;k++){
				if((A[k]-A[j])<A[i]){
					//an acute triangle satisfies a^2+b^2>c^2, b^2+c^2>a^2, and c^2+a^2>b^2.
					if((pw[k]+pw[j]>pw[i])&&(pw[j]+pw[i]>pw[k])&&(pw[i]+pw[k]>pw[j])){
						++res[0];
					}else
					//an obtuse triangle satisfies one of a^2+b^2<c^2, b^2+c^2<a^2, or c^2+a^2<b^2.
					if((pw[k]+pw[j]<pw[i])||(pw[j]+pw[i]<pw[k])||(pw[i]+pw[k]<pw[j])){
						++res[2];
					}else{
						++res[1];
					}

				}else break;
			}
		}
	}
	cout<<res[0]<<" "<<res[1]<<" "<<res[2]+1<<endl;
	return 0;
}

