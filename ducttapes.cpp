//Problem Tape from Hackerearth
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

using ll = long long;

int main()
{
	ll n,k,d;
	cin >> n >> k >> d;
	vector<ll> win(n-k+1);
	vector<ll> dt(n+1,0);
	vector<ll> sm(n+1,0);
	for(int i{1};i<=n;i++)
	{
		cin >> dt[i];
		sm[i] = sm[i-1] + dt[i];
	}
	ll s{0};
	ll w{0};
/*	for(int i{1};i<=n;i++)
	{
		sm[i] = sm[i-1] + dt[i];
		if(i>=k){
			win[w++] = sm[i] - sm[i-k];
		}
	}*/
	ll r{0};
	//Second possible solution
	for(int i{k};i<=n;i++)
	{
		ll p = sm[i] - sm[i-k];
		if(p==0){
			cout<<"-1\n";
			return 0;
		}
		if(p>=d) continue;
		++r;
		ll j = i;
		//Look for the last non zero
		//From this point is possible to extend the 
		//next window
		while(!dt[j])
			--j;
		j = j + k - 1;
		while(!dt[j])
			--j;
		i = j + k - 1;
	}
	//My solution
	/*
	for(auto e:win)
		cout<<e<<",";
	cout<<endl;*/
/*	ll r{0};
	for(int i{0};i<w;i++)
	{
	/*	for(auto e:win)
			cout<<e<<",";
		cout<<endl;*/
	/*	if(win[i]==0)
		{
			cout<<"-1"<<endl;
			return 0;
		}
		if(win[i]-d<0){
			for(int j{min((ll)win.size()-1,i+k)};j>=i;j--)
			{
			//	cout<<"$"<<j<<","<<dt[j+1]<<endl;
				if(dt[j+1]!=0){
					for(int q{j};q<min(j+k-1,w);q++)
						win[q] = d;
				}
			}
			++r;
		}
	}*/
	cout<<r<<endl;
}
