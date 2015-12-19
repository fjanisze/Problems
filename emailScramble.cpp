#include <iostream>
#include <map>
#include <string>
#include <set>
#include <vector>
#include <algorithm>
#include <random>
#include <deque>
#include <atomic>
#include <thread>
#include <chrono>
using namespace std;

using ll = long long;

constexpr const char* email = "My surname + .computing@gmail.com";
constexpr int size = 33;

int data[size][size];

int max_path{0};

//deque<int> path[4];
//deque<int> best_path[4];

int path[4][size];
int best_path[4][size];
int longest[size];

vector<bool> vis[4];
long mx_path[4];
bool running[4];
thread workers[4];

atomic_int running_worker;

long dijkstra(int s,int d,int dist,int th_index,int& st_index)
{
	path[th_index][st_index] = s;
	long r{0};
	if(s==d){
		if(dist>mx_path[th_index]){
			mx_path[th_index] = dist;
			for(int i{0};i<=st_index;i++)
				best_path[th_index][i] = path[th_index][i];
		}
		--st_index;
		return 0;
	}
	vis[th_index][s] = true;
	for(int i{0};i<size;i++)
	{
		if(data[s][i]>0)
		{
			if(s==i || vis[th_index][i] == true) continue;
			++st_index;
			long t = data[s][i] + dijkstra(i,d,dist + data[s][i],th_index,st_index);
			if(t > r)
			{
				r = t;
			}
		}
	}
	vis[th_index][s] = false;
	--st_index;
	return mx_path[th_index];
}

void execute(int s,int d,int dist,int th_index)
{
	int stack_index{1};
	dijkstra(s,d,dist,th_index,stack_index);
	//Saving results.
	if(mx_path[th_index]>max_path){
		max_path = mx_path[th_index];
		mx_path[th_index] = 0;
		for(int i{0};i<size;i++)
			longest[i] = best_path[th_index][i];
	}
	running[th_index] = false;
}

long launch_platform(long s, int d)
{
	for(int i{0};i<4;i++)
	{
		vis[i].resize(size);
		vis[i][0] = true;
		mx_path[i] = 0;
		running[i] = false;
	}
	for(int i{0};i<size;)
	{
		if(data[0][i]==0){
			++i;
			continue;
		}
		bool ok{false};
		for(int r{0};r<4;r++)
		{
			if(running[r]==false)
			{
				if(workers[r].joinable()) workers[r].join();
				for(int i{0};i<size;i++)
				{
					vis[r][i] = false;
					path[r][i] = 0;
					best_path[r][i] = 0;
				}
				vis[r][0] = true;
				mx_path[r] = 0;
				//New spawn
				cout<<"Thread: "<<r<<" free, entering: "<<i<<endl;
				running[r] = true;
				workers[r] = std::thread(execute,i,d,data[s][i],r);
				ok = true;
				break;
			}
		}
		if(ok) ++i;
		else{
			this_thread::sleep_for(chrono::seconds{1});
		}
	}
	cout<<"Joining all\n";
	for(int i{0};i<4;i++)
	{
		if(workers[i].joinable()) workers[i].join();
	}
	return max_path;
}

void create_graph()
{
	random_device rd;
	mt19937 eng(rd());
	normal_distribution<> dist(0,size);
	for(int i{0};i<size;i++)
	{
		for(int j{0};j<size;j++)
		{
			if(i==j || (i==0 && j==size-1)) continue;
			if(generate_canonical<double,10>(eng)<=.46){
				data[i][j] = abs(dist(eng));
			}
		}
	}
	//Print the graph
	for(int i{0};i<size;i++)
	{
		for(int j{0};j<size;j++)
		{
			cout<<data[i][j]<<",";
		}
		cout<<endl;
	}
//	long r = dijkstra(0,size-1,0);
	auto start = chrono::high_resolution_clock::now();
	long r= launch_platform(0,size-1);
	cout<<"Longest: "<<r<<endl;
	auto stop = chrono::high_resolution_clock::now();
	cout<<"Required time: "<<chrono::duration_cast<chrono::seconds>(stop-start).count()<<"s\n";

	map<int,char> mapping;

	for(int i{0};i<size;i++)
	{
		cout<<longest[i]<<",";
		mapping[longest[i]] = email[i];
	}
	cout<<endl;
	for(auto e:mapping)
		cout<<e.first<<" = "<<e.second<<endl;
}

int main()
{
	string s(email);
	cout<<s.size()<<endl;
	create_graph();
}
