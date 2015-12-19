#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

long comb(int n, int k)
{
	if(k>n) return 0;
	if(k==n) return 1;
	long r{1};
	for(int i{1};i<=k;i++)
	{
		r *= double(n-i+1)/i;
	}
	return r;
}

long calculate_index(vector<int>& k_seq,int n)
{
	long r{1},j{0};
	long k{k_seq.size()};
	for(int i{0};i<k;i++)
	{
		for(j++;j!=k_seq[i];j++)
		{
			r += comb(n-j,k-i-1);
		}
	}
	return r;
}

int main()
{
	vector<int> seq = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
	int k{4};
	string b(k,'1');
	b.resize(seq.size(),'0');
	int idx{1};
	vector<int> r;
	string s;
	do{
		bool nl{false};
		for(int i{0};i<b.size();i++)
		{
			if(b[i]!='0'){
				r.push_back(seq[i]);
			}
		}
		string s;
		for(auto e:r)
			s += to_string(e);
		if(s=="3456" || s=="3579" || s=="6789")
			cout<<s<<" - "<<idx<<" , combinatorics index: "<<calculate_index(r,seq.size())<<endl;
		++idx;
		r.clear();
	}while(prev_permutation(b.begin(),b.end()));
}
