#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

constexpr int size = 16;

int dp[size][size];

void prepare(vector<int>& data)
{
	for(int i{0};i<size;i++)
		dp[i][i] = i;
	for(int i{0};i<data.size();i++)
	{
		for(int j{i+1};j<data.size();j++)
		{
			if(data[dp[i][j-1]] < data[j])
			{
				dp[i][j] = dp[i][j-1];
			}else{
				dp[i][j] = j;
			}
		}
	}
}

int main()
{
	vector<int> data = {5,5,6,10,12,15,6,19,3254,153,1,51,561,9};
	prepare(data);
	cout<<"Min in range 2/8: "<<data[dp[9][12]]<<endl;
}
