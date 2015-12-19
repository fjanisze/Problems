#include <iostream>
#include <array>
using namespace std;

array<int, 16> ar;

void put_value(int value,int idx)
{
	while(idx<16)
	{
		ar[idx] += value;
		//Calculate the successor
		idx = idx + (idx & -idx);
	}
}

long get_cumulative(int idx)
{
	long s = ar[0];
	while(idx>0)
	{
		s += ar[idx];
		//Calculate the parent (int the Fenwick tree)
		idx = idx & ( idx - 1);
	}
	return s;
}

long get_value(int idx)
{
	long r = ar[idx];
	if(idx>0)
	{
		long prev = idx & (idx - 1);
		idx -= 1;
		while(prev != idx)
		{
			r -= ar[idx];
			idx = idx & (idx - 1);
		}
	}
	return r;
}

void print()
{
	int i{0};
	for(auto e:ar){
		cout<<"#"<<i++<<":"<<e<<endl;
	}
}

int main()
{
	for(auto& elem:ar)
		elem = 0;
	put_value(3,2);
	put_value(5,2);
	put_value(6,2);
	put_value(4,5);
	put_value(4,4);
	put_value(2,3);
	put_value(3,7);
	put_value(4,13);
	put_value(7,15);
	print();
	cout<<"Cumulative at index 6:"<<get_cumulative(6)<<endl;
	cout<<"Cumulative at index 12:"<<get_cumulative(12)<<endl;
	cout<<"Cumulative at index 2:"<<get_cumulative(2)<<endl;

	cout<<"Specific value at index: 2:"<<get_value(2)<<endl;
	cout<<"Specific value at index: 13:"<<get_value(13)<<endl;
	cout<<"Specific value at index: 8:"<<get_value(8)<<endl;
}
