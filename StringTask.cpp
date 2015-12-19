#include <iostream>
#include <string>
#include <vector>
using namespace std;

constexpr int ti(const char c)
{
	return c -'a';
}

int main()
{
	string s, r;
	cin >> s;
	vector<bool> t('z'-'A'+1,false);
	t[ti('a')] = true;
	t[ti('o')] = true;
	t[ti('y')] = true;
	t[ti('e')] = true;
	t[ti('u')] = true;
	t[ti('i')] = true;
	for(int i{0};i<s.size();i++)
	{
		s[i] = tolower(s[i]);
		if(t[ti(s[i])]){
			continue;
		}else{
			r += '.';
			r += s[i];
		}
	}
	cout<<r<<endl;
}
