#include <iostream>
#include <vector>
using namespace std;

int solve(vector<vector<int>>& data)
{
	int c{0};
	for(int i{1};i<data.size();i++)
	{
		if(data[c][i]){
			c = i;
		}
	}
	cout<<"#:"<<c<<endl;
	for(int i{0};i<data.size();i++)
	{
		if(c==i) continue;
		if(data[c][i]!=0 || data[i][c]!=1){
			c = -1;
			break;
		}
	}
	return c;
}

int main()
{
	vector<vector<int>> d = {
		{1,0,0,0,0},
		{1,0,0,0,0},
		{1,1,0,0,0},
		{1,0,0,0,0},
		{1,0,0,0,0}
	};
	cout<<solve(d)<<endl;
	return 0;
}
