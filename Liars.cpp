//Problem from Hackerrank
#include <vector>
#include <iostream>
#include <utility>
#include <algorithm>
#include <limits>
#include <queue>
using namespace std;

constexpr int size{105};
constexpr int inf = numeric_limits<int>::max();
int n,m;
int mp[size][size];
int lmin{inf};


int bfs(int s,int d)
{
	queue<int> Q;
	vector<int> dist(size,inf);
	vector<bool> v(size,false);
	dist[s] = 0;
	Q.push(s);
	v[s] = true;
	while(!Q.empty())
	{
		int c = Q.front();
		Q.pop();
		v[c] = false;
		for(int i{0};i<=n;i++)
		{
			if(mp[c][i]!=inf)
			{
				int l = dist[c] + mp[c][i];
				if(l < dist[i])
				{
					dist[i] = l;
					if(!v[i])
					{
						Q.push(i);
						v[i] = true;
					}
				}
			}
		}
	}
	return dist[d];
}

int main()
{
	cin >> n >> m;
	for(int i{0};i<size;i++)
		for(int j{0};j<size;j++)
			mp[i][j] = inf;
	for(int i{0};i<m;i++)
	{
		int a,b,l;
		cin >> a >> b >> l;
		mp[a-1][b] = l;
		mp[b][a-1] = -l;
	}
	for(int i{0};i<n;i++)
	{
		mp[i][i+1] = 1;
		mp[i+1][i] = 0;
	}
	cout<<-bfs(n,0)<<" "<<bfs(0,n)<<endl;
}
