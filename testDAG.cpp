#include <iostream>
#include <queue>
#include <vector>
using namespace std;

constexpr int size{33};

int matrix[size][size];
vector<bool> V(size,false);
vector<bool> R(size,false);

bool solve(int s)
{
	if(V[s]==false)
	{
		V[s] = true;
		R[s] = true;
		for(int i{0};i<size;i++)
		{
			if(matrix[s][i]>0)
			{
				if(V[i]==false && solve(i))
					return true;
				else if(R[s]==true)
					return true;
			}
		}
	}

	R[s] = false;
	return false;
}

int main()
{
	for(int i{0};i<size;i++)
	{
		for(int j{0};j<33;j++)
			cin >> matrix[i][j];
	}
	bool hasCycle = solve(0);
	if(hasCycle==true)
		cout<<"Has cycles\n";
	else
		cout<<"No cycles\n";
}
