//http://codeforces.com/problemset/problem/616/D
#include <iostream>
#include <vector>
#include <utility>
using namespace std;

//Need a fast mapping, std::map is too slow.
long cnt[1000001];

pair<long,long> solution(long k, const vector<long>& A)
{
	long current_l{0},current_k{0},r{0},l{0},N{(long)A.size()};
	for(long current_r{0};current_r<N;current_r++)
	{
		//Have we encountered a new element?
		if(++cnt[A[current_r]]==1)
			++current_k;
		if(current_k>k)
		{
			//We need to remove something
			while(--cnt[A[current_l]]>0)
				++current_l;
			++current_l;
			--current_k;
		}
		//Any better solution to our problem?
		if((r-l)<(current_r-current_l))
			l = current_l, r = current_r;
	}
	return make_pair(l+1,r+1);
}

pair<long,long> solution2_editorial(long k, const vector<long>& A)
{
	long l{0},r{0},current_l{0},current_k{0},N{(long)A.size()};
	for(long i{0};i<N;i++)
	{
		while(current_l<N)
		{
			//Add the element to the current window,
			//this may increase the window size.
			if(++cnt[A[current_l]]==1)
				++current_k;
			if(current_k>k)
			{
				//Too much elements
				if(--cnt[A[current_l]]==0)
					--current_k;
				break;
			}
			++current_l;
		}
		//Check wether we found a longest subsequence
		if((r-l)<(current_l-i))
			l = i, r = current_l;
		//Remove the elements at the 'head' of the subsequence
		if(--cnt[A[i]]==0)
			--current_k;
	}
	return make_pair(l+1,r);
}

int main()
{
	std::ios::sync_with_stdio(false);
	long n,k;
	cin >> n >> k;
	vector<long> d(n);
	for(int i{0};i<n;i++)
		cin >> d[i];
	auto r = solution(k,d);
	cout<<r.first<<" "<<r.second<<endl;
}
