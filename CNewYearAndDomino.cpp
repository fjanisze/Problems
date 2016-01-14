//http://codeforces.com/contest/611/problem/C
#include <iostream>
#include <vector>
using namespace std;

int mp[505][505];
int oriz[505][505];
int vert[505][505];

int main()
{
	int h,w;
	cin >> h >> w;
	for(int i{1};i<=h;i++)
	{
		for(int j{1};j<=w;j++)
		{
			char ch;
			cin >> ch;
			if(ch=='.')
				mp[i][j] = 1;
		}
	}
	//Perform the domino calculations
	for(int i{1};i<=h;i++)
	{
		for(int j{1};j<=w;j++)
		{
			oriz[i][j] = oriz[i-1][j] + oriz[i][j-1] - oriz[i-1][j-1];
			vert[i][j] = vert[i-1][j] + vert[i][j-1] - vert[i-1][j-1];
			if(mp[i][j]!=1) continue;
			if(mp[i][j-1]==1) ++oriz[i][j];
			if(mp[i-1][j]==1) ++vert[i][j];
		}
	}
	int q;
	cin >> q;
	while(q--)
	{
		int r1,r2,c1,c2;
		cin >> r1 >> c1 >> r2 >> c2;
		int r=oriz[r2][c2]-oriz[r1-1][c2]-oriz[r2][c1]+oriz[r1-1][c1];
		r+=vert[r2][c2]-vert[r2][c1-1]-vert[r1][c2]+vert[r1][c1-1];
		cout<<r<<endl;
	}
}
