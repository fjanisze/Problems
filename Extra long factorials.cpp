#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string mult(char c,string s)
{
//	reverse(s.begin(),s.end());
	int carry{0};
	string result;
	for(int i{0};i<s.size();i++)
	{
		int p = s[i]-'0';
		p*= (c-'0');
		if(carry)
		{
			p+=carry;
			carry = 0;
		}
		if(p>=10)
		{
			carry = p/10;
			p-=carry*10;
		}
		result.push_back(p+'0');
	}
	if(carry)
		result.push_back(carry+'0');
//	reverse(result.begin(),result.end());
	return result;
}

string mult(string f,string s)
{
	reverse(f.begin(),f.end());
	reverse(s.begin(),s.end());
	while(f.size()>s.size()) s+='0';
	while(s.size()>f.size()) f+='0';
	vector<string> partials(f.size());
	string result;
	size_t l{0};
	for(int i{0};i<f.size();i++)
	{
		int c = f[i];
		partials[i] = mult(c,s);
		for(int j{0};j<i;j++)
			partials[i].insert(partials[i].begin(),'0');
		//reverse(partials[i].begin(),partials[i].end());
		l=max(l,partials[i].size());
	}
	int sum,c{0};
	for(int col{0};col<l;col++)
	{
		sum = 0;
		for(auto& p:partials)
		{
			if(p.size()<=col) continue;
			sum += p[col]-'0';
		}
		sum+=c;
		c=0;
		if(sum>=10)
		{
			c=sum/10;
			sum-=c*10;
		}
		result.push_back(sum+'0');
	}
	while(result.back()=='0')
		result.pop_back();
	reverse(result.begin(),result.end());
	return result;
}

string fac(int n)
{
	if(n==0) return "1";
	if(n==1) return "1";
	if(n==2) return "2";

	char buf[3];

	string f = "1";
	string s = "2";

	for(int cur{3};cur<=n;cur++)
	{
		f = mult(f,s);
		itoa(cur,buf,10);
		s = buf;
	}
	string result = mult(f,s);
	return result;
}

int main()
{
	cout<<fac(25)<<endl;
}
