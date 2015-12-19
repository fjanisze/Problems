#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int mx[1001];
int my[1001];
vector<bool> visited(1001,false);

long dfs(int s)
{
	stack<int> Q;
	Q.push(s);
	int r{0};
	while(!Q.empty())
	{
		int c = Q.top();
		Q.pop();
		visited[c] = true;
		for(int i{0};i<1001;i++)
		{
			if(visited[i]==false && ( mx[i]==mx[c] || my[i]==my[c] ))
			{
				Q.push(i);
			}
		}
	}
	return r;
}

int main()
{
	int n;
	cin >> n;
	if(n==1){
		cout<<"0\n";
		return 0;
	}
	vector<int> p;
	for(int i{0};i<n;i++)
	{
		cin >> mx[i] >> my[i];
	}
	int r{0};
	for(int i{0};i<n;i++)
	{
		if(!visited[i]){
			++r;
			dfs(i);
		}
	}
	cout<<r-1<<endl;
	return 0;
}
