#include <iostream>
#include <vector>
using namespace std;

long solve(vector<vector<int>>& d,int x,int y)
{
	if(x>=d[0].size() || y>=d.size()) return 0;
	if(d[x][y]==0) return 0;
	if(x==2&&y==2) return 1;
	long s{0};
	s += solve(d,x+1,y);
	s += solve(d,x+1,y+1);
	s += solve(d,x,y+1);
	return s;
}

int main()
{
	vector<vector<int>> q1 = 
	{
		{1,1,1},
		{1,1,1},
		{1,1,1}
	};
	vector<vector<int>> q2 = 
	{
		{1,1,1},
		{0,0,1},
		{0,0,1}
	};
	vector<vector<int>> q3 = 
	{
		{1,1,1},
		{0,0,1},
		{0,0,1}
	};
	vector<vector<int>> q2 = 
	{
		{1,1,1},
		{0,0,1},
		{0,0,1}
	};



	cout<<solve(q1,0,0)<<endl;
	cout<<solve(q2,0,0)<<endl;
}
