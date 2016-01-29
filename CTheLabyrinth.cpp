//http://codeforces.com/problemset/problem/616/C
#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

long labyrinth[1001][1001];
map<long,long> conn_comp_size;
int mark{-1};
int n,w;
int used_marks[4];
int marks_i{0};

long dfs(int x,int y)
{
	if(labyrinth[y][x]<=0) return 0;
	++conn_comp_size[-mark];
	long r{1};
	labyrinth[y][x] = mark;
	if(x-1>=0) r+=dfs(x-1,y);
	if(x+1<w) r+=dfs(x+1,y);
	if(y-1>=0) r+=dfs(x,y-1);
	if(y+1<n) r+=dfs(x,y+1);
	return r;
}

bool try_to_mark(int pattern)
{
	if(pattern==0) return false;
	for(int i{0};i<marks_i;i++)
		if(used_marks[i]==pattern)
			return false;
	used_marks[marks_i++] = pattern;
	return true;
}

int main()
{
	std::ios::sync_with_stdio(false);
	cin >> n >> w;
	string s;
	for(int i{0};i<n;i++)
	{
		cin >> s;
		for(int j{0};j<w;j++)
		{
			labyrinth[i][j] = (s[j] == '.') ? 1 : 0;
		}
	}
	//Mark each connected component size:
	for(int i{0};i<n;i++)
	{
		for(int j{0};j<w;j++)
		{
			if(labyrinth[i][j]>0)
			{
				dfs(j,i);
				--mark;
			}
		}
	}
	//Solve the problem:
	for(int i{0};i<n;i++)
	{
		for(int j{0};j<w;j++)
		{
			if(labyrinth[i][j]==0)
			{
				long r{1};
				if(j-1>=0){
					if(try_to_mark(labyrinth[i][j-1]))
						r+=conn_comp_size[-labyrinth[i][j-1]];
				}
				if(j+1<w){
					if(try_to_mark(labyrinth[i][j+1]))
						r+=conn_comp_size[-labyrinth[i][j+1]];
				}
				if(i-1>=0){
					if(try_to_mark(labyrinth[i-1][j]))
						r+=conn_comp_size[-labyrinth[i-1][j]];
				}
				if(i+1<n){
					if(try_to_mark(labyrinth[i+1][j]))
						r+=conn_comp_size[-labyrinth[i+1][j]];
				}
				cout<<r%10;
				//CLearn the marks
				marks_i = 0;
				used_marks[0] = used_marks[1] = 0;
			       	used_marks[2] = used_marks[3] = 0;
			}
			else cout<<'.';
		}
		cout<<endl;
	}
}
