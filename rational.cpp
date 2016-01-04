#include <iostream>
#include <vector>
#include <cmath>
#include <sstream>
#include <math.h>
#include <iomanip>
#include <utility>
using namespace std;

#define eps 1e-9
#define lim 50

using ld = long double;
using fc = std::pair<long,long>;
using vi = vector<int>;

fc to_fc(vi& n)
{
	fc r;
	r.first = n[0];
	long nom{1},den{n.back()};
	for(int i{n.size()-1};i>0;i--)
	{
		int t = den;
		den = den*n[i-1]+nom;
		nom = t;
	}
	r.first = den;
	r.second = nom;
	return r;
}

void to_cf(fc num)
{
	//cout<<num.first<<"/"<<num.second<<endl;
	long nom{num.first},den{num.second};

	if(den==1)
	{
		cout<<nom;
	}
	else{
		while(den > 0)
		{
			long t = nom / den;
			cout<<t<<" ";
			nom = nom - t * den;
			t = nom;
			nom = den;
			den = t;
		}
	}
	cout<<endl;
}

void read_data(int n, vector<int>& d)
{
	for(int i{0};i<n;i++){
		int k;
		cin >> k;
		d.push_back(k);
	}
}

int main()
{
	int n;
	int n2;
	int cn{1};
	while(cin)
	{
		vi a,b;
		cin >> n;
		if(n<0) break;
		cin >> n2;
		a.clear();
		b.clear();
		read_data(n,a);
		read_data(n2,b);
		fc f = to_fc(a), s = to_fc(b);
		cout<<"Case "<<cn++<<":"<<endl;
		fc sm = make_pair(f.first*s.second + f.second*s.first,f.second*s.second);
		to_cf(sm);
		fc sb = make_pair(f.first*s.second-s.first*f.second,f.second*s.second);
		to_cf(sb);
		fc ml = make_pair(f.first*s.first,f.second*s.second);
		to_cf(ml);
		fc dv = make_pair(f.first*s.second,f.second*s.first);
		to_cf(dv);

		n = -1;
	}
}
