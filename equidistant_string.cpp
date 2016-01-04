#include <iostream>
#include <string>
using namespace std;

string do_job(string& a,string& b,bool a_first)
{
	string r;
	long ca{0},cb{0};
	for(int i{0};i<a.size();i++)
	{
		if(a[i]==b[i]){
			r+=(a[i]=='1'?'0':'1');
		}
		else{
			if(a_first){
				r+=a[i];
				++ca;
			}else{
				r+=b[i];
				++cb;
			}
			a_first ^= 1;
		}
	}
	return ca==cb ? r : "impossible";
}

int main()
{
	string a,b;
	cin >> a >> b;
	string r1 = do_job(a,b,true);
	string r2 = do_job(a,b,false);
	if(r1 != "impossible"){
		cout<<r1<<endl;
	}
	else{
		cout<<r2<<endl;
	}
	return 0;
}
