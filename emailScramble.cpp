#include <iostream>
#include <mutex>
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
constexpr int cores = 8;

int data[size][size];

int max_path{0};

int path[cores][size];
int best_path[cores][size];
int longest[size];

vector<bool> vis[cores];
long mx_path[cores];
bool running[cores];
thread workers[cores];

atomic_int running_worker;
ll dfs_call;
ll path_found;
ll path_found_last;
mutex call_print_mutex;
std::chrono::time_point<chrono::high_resolution_clock> start;

long dfs(int s,int d,int dist,int th_index,int& st_index)
{
	++dfs_call;
	if(dfs_call%1000000000==0){
		if(call_print_mutex.try_lock()==true){
			auto cur_time = chrono::high_resolution_clock::now();
			ll execution_time = chrono::duration_cast<chrono::seconds>(cur_time-start).count();
			cout<<"Path found:" <<path_found<<" ("<<(path_found-path_found_last)/execution_time<<" p/s), still counting. time "<<execution_time<<"s"<<endl;
			call_print_mutex.unlock();
		}
	}
	path[th_index][st_index] = s;
	long r{0};
	if(s==d){
		if(dist>mx_path[th_index]){
			mx_path[th_index] = dist;
			for(int i{0};i<=st_index;i++)
				best_path[th_index][i] = path[th_index][i];
		}
		--st_index;
		++path_found;
		return mx_path[th_index];
	}
	vis[th_index][s] = true;
	for(int i{0};i<size;i++)
	{
		if(data[s][i]>0)
		{
			if(s==i || vis[th_index][i] == true) continue;
			++st_index;
			long t = data[s][i] + dfs(i,d,dist + data[s][i],th_index,st_index);
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
	dfs(s,d,dist,th_index,stack_index);
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
	for(int i{0};i<cores;i++)
	{
		vis[i].resize(size);
		vis[i][0] = true;
		mx_path[i] = 0;
		running[i] = false;
	}
	start = chrono::high_resolution_clock::now();
	for(int i{0};i<size;)
	{
		if(data[0][i]==0){
			++i;
			continue;
		}
		bool ok{false};
		for(int r{0};r<cores;r++)
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
	for(int i{0};i<cores;i++)
	{
		if(workers[i].joinable()) workers[i].join();
	}
	cout<<"DFS call: "<<dfs_call<<endl;
	cout<<"Number of path found: "<<path_found<<endl;
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
			if(generate_canonical<double,10>(eng)<=.17){
				data[i][j] = abs(dist(eng));
			}
		}
	}
	/*
	vector<vector<int>> matrix = {
	{0,0,0,12,0,0,2,3,1,17,46,0,0,9,6,0,0,24,0},
	{0,0,23,0,0,28,0,0,0,0,0,0,0,13,0,1,0,3,5},
	{6,0,0,16,0,0,0,0,4,0,0,0,0,28,5,16,0,21,0},
	{19,14,0,0,0,6,0,1,0,10,1,5,8,0,0,0,14,0,4},
	{0,0,9,0,0,0,0,7,19,0,0,0,0,0,0,0,0,20,5},
	{0,1,0,0,0,0,0,0,5,5,0,23,39,16,0,0,0,0,9},
	{0,0,0,40,1,7,0,0,0,0,20,13,0,14,0,10,0,0,0},
	{0,16,10,5,0,0,22,0,0,3,0,0,0,8,14,0,0,1,0},
	{0,0,0,0,0,16,11,13,0,0,0,10,0,18,20,0,12,14,8},
	{45,0,0,19,14,16,0,0,0,0,0,0,44,0,0,6,9,17,25},
	{0,0,31,0,22,0,15,0,0,19,0,37,6,0,0,42,0,0,0},
	{0,0,0,0,0,11,0,0,4,14,0,0,0,7,0,0,5,27,0},
	{0,0,10,0,0,23,0,0,0,0,26,0,0,1,0,11,0,0,12},
	{0,0,0,0,0,24,0,0,0,18,19,17,0,0,22,8,44,0,0},
	{0,4,35,0,10,0,0,20,0,22,0,0,34,35,0,20,1,0,5},
	{0,0,0,5,20,0,0,0,0,0,0,9,2,0,0,0,27,43,14},
	{0,3,12,25,0,0,0,0,7,0,0,19,0,0,1,0,0,18,0},
	{31,24,0,0,0,0,15,0,1,32,11,0,32,0,0,0,38,0,0},
	{8,0,0,2,0,0,0,0,0,0,15,0,7,0,0,0,12,0,0}
	};
	//0,10,15,4,8,14,7,6,3,1,5,12,2,13,16,11,17,9,18,
	*/
	//Print the graph
	for(int i{0};i<size;i++)
	{
		cout<<"{";
		for(int j{0};j<size;j++)
		{
	//		data[i][j] = matrix[i][j];
			cout<<data[i][j]<<(j<size-1?",":"");
		}
		cout<<"}"<<endl;
	}
//	long r = dfs(0,size-1,0);
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
