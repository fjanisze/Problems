#include <iostream>
#include <string>
#include <queue>
using namespace std;

int main()
{
	priority_queue<int,vector<int>,greater<int>> Q;
	string s;
	cin >> s;
	for(auto e:s)
	{
		if(e=='+') continue;
		Q.push(e-'0');
	}
	while(!Q.empty())
	{

		int c = Q.top();
		Q.pop();
		cout<<c;
		if(!Q.empty()) cout<<"+";
	}
}
