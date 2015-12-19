/*
#include <iostream>
#include <string>
#include <algorithm>
#include <array>
#include <map>
using namespace std;

int count(string s)
{
	int c{0};
	for(int i{0};i<s.size();i++)
	{
		for(int l{i};l<s.size();l++)
		{
			for(int j{i};j<=l;j++)
			{
				if(s[j]=='1'){
					++c;
					break;
				}
			}
		}
	}
	return c;
}

int main()
{
	long n;
	cin >> n;
	string s;
	for(int i{0};n>0;i++)
	{
		s.push_back(char('0'+int(n&1)));
		n>>=1;
	}
	reverse(s.begin(),s.end());
	cout<<s<<endl;
	for(int l{1};l<=s.size();l++)
	{
		for(int i{0};i<l-1;i++)
			cout<<"0,";
		for(int x{l-1};x<s.size();x++)
		{
			cout<<count(s.substr(x-l+1,l))<<",";
		}
		cout<<endl;
	}
}
*/
/*
int main()
{
	string s;
	int n;
	for(int n{0};n<=16;n++)
	{
		cout<<"# "<<n<<":"<<endl;
		string s;
		for(int w{0};w<4;w++)
		{
			s += (( n>>w ) & 1)?'1':'0';
		}
		reverse(s.begin(),s.end());
		for(int l{1};l<=s.size();l++)
		{
			for(int i{0};i<l-1;i++)
				cout<<"0,";
			for(int x{l-1};x<s.size();x++)
			{
				cout<<count(s.substr(x-l+1,l))<<",";
			}
			cout<<endl;
		}
	}
	return 0;
}
*/

#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;
long long num[1000007];

long brute_force(string s,int K)
{
	int r{0};
	for(int i{0};i<s.size();i++)
	{
		for(int j{0};j<=i;j++)
		{
			int cnt{0};
			for(int k{j};k<=i;k++)
			{
				if(s[k]=='1'){
					cnt++;
				}
			}
			if(cnt==K)
			{
				++r;
			}
		}
	}
	return r;
}

long smart_force(string s,int K)
{
	int dp[100];
	for(int i{0};i<100;i++)
	{
		dp[i] = 0;
	}
	dp[0] = 1;
	int cnt{0};
	int r{0};
	for(int i{0};i<s.size();i++)
	{
		if(s[i]=='1') ++cnt;
		if(cnt>=K)
		{
			cout<<"@: "<<dp[cnt-K]<<endl;
			r += dp[cnt-K];
		}
		++dp[cnt];
	}
	return r;
}

int main()
{
	string str;
	int k,cnt=0;long long ans=0;
	cin >> k;
	cin >> str;
	cout<<"Brute force: "<<brute_force(str,k)<<endl;
	cout<<"Smart force: "<<smart_force(str,k)<<endl;
	return 0;
}
