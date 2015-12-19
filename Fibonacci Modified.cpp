#include <iostream>
#include <string>
#include <algorithm>
#include <chrono>
using namespace std;
using namespace chrono;

long single_mult_time{0};
long single_mult_call{0};

string mult(char c,string s)
{
	++single_mult_call;
	auto start = high_resolution_clock::now();
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
	auto stop = high_resolution_clock::now();
	single_mult_time += duration_cast<milliseconds>(stop-start).count();
	return result;
}


string ssum(string f,string s)
{
	string result;
	int sum,c{0};
	for(int col{0};col<max(f.size(),s.size());col++)
	{
		int a,b;
		if(col>=f.size()) a =0;
		else a = f[col]-'0';
		if(col>=s.size()) b=0;
		else b = s[col]-'0';
		sum =a+b+c;
		c=0;
		if(sum>=10)
		{
			c=sum/10;
			sum-=c*10;
		}
		result.push_back(sum+'0');
	}
	if(c) result.push_back(c+'0');
	return result;
}

long mult_time{0};
long matrix_sum_time{0};

string slowmult(string f,string s)
{
	while(f.size()>s.size()) s+='0';
	while(s.size()>f.size()) f+='0';
	string result;
	size_t l{0};
	vector<string> dp;
	for(int i{0};i<=9;i++)
		dp.push_back("?");
	int psize = f.size();
	const char** nbr = new const char*[psize];
	long* nbr_size = new long[psize];
	for(int i{0};i<f.size();i++)
	{
		int c = f[i];
		short j=c-'0';
		if(dp[j]=="?"){
			dp[j] = mult(c,s);
		}
		nbr[i]=dp[j].c_str();
		nbr_size[i]=dp[j].size();
		l=max(l,dp[j].size()+i);
	}
	int sum,c{0};
	for(int col{0};col<l;col++){
		sum = 0;
		for(int num{0};num<std::min(psize,col+1);num++){
			if((col-num)>=nbr_size[num]) continue;
			sum+=(nbr[num][col-num]-'0');
		}
		sum+=c;
		c=0;
		if(sum>=10){
			c=sum/10;
			sum-=c*10;
		}
		result.push_back(sum+'0');
	}
	delete[] nbr;
	delete[] nbr_size;
	while(!result.empty()&&result.back()=='0') result.pop_back();
	return result;
}

string mult(string f,string s)
{
	auto start = high_resolution_clock::now();
	while(f.size()>s.size()) s+='0';
	while(s.size()>f.size()) f+='0';
	vector<int> partials(f.size(),-1);
	string result("0");
	size_t l{0};
	vector<string> dp;
	for(int i{0};i<=9;i++)
		dp.push_back("?");
	for(int i{0};i<f.size();i++)
	{
		int c = f[i];
		short j=c-'0';
		if(dp[j]=="?"){
			dp[j] = mult(c,s);
		}
		partials[i] = j;
		l=max(l,dp[j].size()+i);
	}
	auto sum_start = high_resolution_clock::now();
	int sum,c{0};
	std::vector<string> elems;
	for(int i{0};i<=9;i++)
		elems.push_back("0");
	string current_mult("1");
	for(int i{0};i<partials.size();i++){
		if(partials[i]<0) continue;
		elems[partials[i]] = ssum(elems[partials[i]],current_mult);
		current_mult.insert(current_mult.begin(),'0');
	}

	for(int i{0};i<elems.size();i++){
		if(elems[i]=="0") continue;
		result = ssum( result, slowmult(elems[i],dp[i]));
	}
	auto stop = high_resolution_clock::now();
	mult_time += duration_cast<milliseconds>(sum_start-start).count();
	matrix_sum_time += duration_cast<milliseconds>(stop-sum_start).count();
	return result;
}


int main() {
	long long f,s,n;
	cin>>f>>s>>n;
	if(n==1) return f;
	if(n==2) return s;
	string f_s = to_string(f),s_s = to_string(s);
	reverse(f_s.begin(),f_s.end());
	reverse(s_s.begin(),s_s.end());
	for(int i{3};i<=n;i++){
		string next = mult(s_s,s_s);
		next = ssum(next,f_s);
		f_s=s_s;
		s_s=next;
	}
	reverse(s_s.begin(),s_s.end());
	cout<<s_s<<endl;
	cout<<"Multiplication time: "<<mult_time<<"("<<single_mult_call<<":"<<single_mult_time<<"), summing time: "<<matrix_sum_time<<", Total: "<<mult_time + matrix_sum_time<<endl;
	return 0;
}

