//From topcoder
#include <iostream>
#include <vector>
#include <string>
#include <stack>
using namespace std;

int mp[51][51];
int V;

class ShortestPathWithMagic
{
	vector<bool> vis;
	double r{1e9};
	void find_path(int f,int t,int k,double d)
	{
		if(f==t){
			r = min(d,r);
			return;
		}
		if(vis[f]==true) return;
		if(d>r) return ;
		vis[f] = true;
		for(int i{0};i<V;i++)
		{
			//cout<<"#:"<<f<<","<<t<<","<< mp[c][i]<<endl;
			if(k>=1){
				find_path(i,t,k-1, d + double(mp[f][i])*.5);
			}
			find_path(i,t,k, d + double(mp[f][i]));
		}
		vis[f] = false;
	}
public:
	double getTime(vector<string> d, int k)
	{
		V = d.size();
		for(int i{0};i<d.size();i++)
		{
			for(int j{0};j<d[i].size();j++)
			{
				mp[i][j] = d[i][j]-'0';
			}
		}
		vis.resize(V+1,false);
		find_path(0,1,k,0);
		return r;
	}
};

int main()
{
	ShortestPathWithMagic p;
	vector<string> s1 = {"094", "904", "440"};
	vector<string> s2 = {"076237", "708937", "680641", "296059", "334508", "771980"};
	vector<string> s3 = {"09247266124", "90123790803", "21068509704", "42607851294", "73870470851", "27584008427", "69057008220", "60910880035", "18728420068", "20095223606", "43441705860"};
	cout<<p.getTime(s3,1)<<endl;
	//cout<<p.getTime(s2,1)<<endl;

}
