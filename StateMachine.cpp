#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int solution(string& S)
{
	stack<int> tokens;
	for(int i{0};i<S.size();i++)
	{
		if(S[i]=='+' || S[i]=='*')
		{
			if(tokens.size()<2) 
				return -1;
			int op1 = tokens.top();
			tokens.pop();
			int op2 = tokens.top();
			tokens.pop();
			int res{-1};
			if(S[i]=='+'){
				res = op1+op2;
				if((res-op1)!=op2)
					return -1;
			}
			else{
				res = op1*op2;
				if(res!=0 && res/op1!=op2)
					return -1;
			}
			tokens.push(res);
		}
		else
			tokens.push(S[i]-48);
	}
	if(tokens.empty())
		return -1;
	return tokens.top();
}

int main()
{
	string s;
	cin >> s;
	cout<<solution(s)<<endl;
}
