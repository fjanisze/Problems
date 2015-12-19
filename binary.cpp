#include <iostream>
#include <vector>
using namespace std;

int binary(vector<int>& data,int v,int l, int r)
{
	long loops{0};
	long res{-1};
	while(l<=r)
	{
		++loops;
		int m = (l+r)/2;
		if(data[m]==v){
			res = loops;
			break;
		}
		if(data[m]>v) r = m-1;
		else l = m + 1;
	}
	return res;
}

long do_the_job(int size)
{
	int c{0};
	int w{1};
	int n{1};
	int l{0};
	while(l<size){
		int k = (min(size-l,w));
		c+=k*n;
		l+=k;
		++n;
		w*=2;
	}
	return c;
}

int main()
{
	vector<int> data;
	int last_loop{0};
	for(int i{0};i<322;i++)
	{
		data.push_back(i);
		int loops{0};
		for(int j{0};j<=i;j++)
		{
			int t = binary(data,j,0,data.size()-1);
			if(t<0) cout<<"FUCK\n";
			loops += t;
		}
		cout<<"elems: "<<data.size()<<", loops: "<<loops<<", +"<<(loops-last_loop)<<" Calculated: "<<do_the_job(data.size())<<endl;
		last_loop = loops;
	}
}
