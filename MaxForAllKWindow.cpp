#include <iostream>
#include <vector>
using namespace std;


int main()
{
	vector<int> data = {5,5,6,10,12,15,6,19,3254,153,1,51,561,9};
	int k;
	cin >> k;

	vector<int> lr(data.size(),1e9);
	vector<int> rl(data.size(),1e9);
	//Beginning of a block
	for(int i{0};i<data.size();i++)
	{
		if(i%k==1 || i==0){
			lr[i] = data[i];
		}else{
			lr[i] = min(data[i],lr[i-1]);
		}
	}
	//End of a block
	for(int i{data.size()-1};i>=0;i--)
	{
		if(i==data.size()-1){
			rl[i] = data[i];
		}
		else if(i%k==0){
			rl[i] = data[i];
		}else{
			rl[i] = min(data[i],rl[i+1]);
		}
	}

	for(auto e:lr)
		cout<<e<<",";
	cout<<endl;
	for(auto e:rl)
		cout<<e<<",";
	cout<<endl;

	//Print all the minimum for all the window of size k
	for(int i{0};i<data.size()-k+1;i++)
	{
		cout<<min(rl[i],lr[i+k-1])<<endl;
	}
}
