#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool inversions(vector<int>& data)
{
	int count{0};
	for(int i{0};i<data.size();i++)
	{
		int m=i;
		for(int j=data.size()-1;j>i;j--)
		{
			if(data[m]>data[j])
			{
				m=j;
				break;
			}
		}
		if(m!=i){
		//	cout<<data[i]<<","<<data[m]<<endl;
			if(++count>1) return false;
			swap(data[i],data[m]);
			i = 0;
		};
	}
	return true;
}

bool solution(vector<int> &A) {
	return inversions(A);
}

int main()
{
	vector<int> data = {1,1,9,4,6};
	cout<<solution(data)<<endl;
	for(auto e:data)
		cout<<e<<",";
	cout<<endl;
}
