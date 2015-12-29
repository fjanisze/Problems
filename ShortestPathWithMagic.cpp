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
	stack<int> path;
	void find_path(int f,int t,int k,double d)
	{
		path.push(f);
		if(f==t){
			//cout<<"@:"<<f<<","<<k<<","<<d<<endl;
			r = min(d,r);
			stack<int> p_path = path;
			while(p_path.size()>0)
			{
				cout<<p_path.top()<<",";
				p_path.pop();
			}
			cout<<" = "<<r<<endl;
			path.pop();
			return;
		}
		if(vis[f]==true)
		{
			path.pop();
			return;
		}
		if(d>r){
			path.pop();
		       	return ;
		}
		vis[f] = true;
		for(int i{0};i<V;i++)
		{
			if(mp[f][i]==0) continue;
			if(k>=1){
				find_path(i,t,k-1, d + double(mp[f][i])*.5);
			}
			find_path(i,t,k, d + double(mp[f][i]));
		}
		path.pop();
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
				cout<<d[i][j];
			}
			cout<<endl;
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
	cout<<p.getTime(s2,2)<<endl;
	//cout<<p.getTime(s2,1)<<endl;

}
