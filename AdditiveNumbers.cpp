#include <iostream>
#include <string>
using namespace std;

using ll = long long;

class Solution {
	ll get_number(int s,int e,string& str)
	{
		if(s<0 || e<0 || e<s) return -1;
		ll n{0},m{1};
		if(s==e)
		{
			return str[e]-48;
		}
		for(;s<=e;e--,m*=10){
			if(s==e && (str[e]-48)==0) return -1;
			n += (m*(str[e]-48));
		}
		return n;
	}
public:
	bool isAdditiveNumber(string num,int force_sol_size = -1) {
	//	cout<<"#: "<<num<<","<<force_sol_size<<endl;
		if(num.empty()) return true;
		int e = num.size()-1;
		ll add1{-1},add2{-1};
		int s{e};
		if(force_sol_size>0)
		{
			s = e - force_sol_size + 1;
		}
		for(;s>=2;s--)
		{
			int len = e-s+1;
			ll sol = get_number(s,e,num);
			if(sol<0) continue;
	//		cout<<"@: "<<sol<<","<<len<<endl;
			bool found{false},is_end{false};
			for(int i{0};i<len && !found;i++)
			{
				for(int j{0};j<len;j++)
				{
					add2 = get_number(s-1-i,s-1,num);
					add1 = get_number(s-2-i-j,s-2-i,num);
	//				cout<<add1<<"+"<<add2<<endl;
					if(add1 < 0 || add2 < 0)
					{
						if(s-2-i-j==0) is_end = true;
						continue;
					}
					if(add2+add1==sol)
					{
						found = true;
						if(s-2-i-j==0) is_end = true;
						break;
					}
				}
			}
			if(found)
			{
	//			cout<<add1<<"+"<<add2<<"="<<sol<<endl;
				if(is_end)
					return true;
				bool r = isAdditiveNumber(num.substr(0,s),to_string(add2).size());
				if(r==true) return true;
			}
			if(is_end) break;
		}
		return false;
	}
};

int main()
{
	string s;
	cin >> s;
	Solution sol;
	cout<<"Is additive?: "<<sol.isAdditiveNumber(s)<<endl;
}
