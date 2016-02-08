//http://codeforces.com/problemset/problem/597/C
#include <iostream>
#include <vector>
#include <chrono>
#include <functional>
#include <numeric>
using namespace std;

using ll = long long;
constexpr ll max_n{100001};

ll num_of_elements;
ll max_k;
ll cum[max_n][12];
vector<ll> data;

//The right algorithm with the wrong data structure
namespace brute_force
{

    void update_cum(ll val,int start_index,int k)
    {
        for(int i{start_index};i<=num_of_elements;i++)
        {
            cum[i][k] += val;
        }
    }

    ll run()
    {
        update_cum(1,0,0);
        for(ll i{1};i<=num_of_elements;i++)
        {
            for(int k{1};k<=max_k;k++)
            {
                ll cur_cum = cum[data[i]-1][k-1];
                update_cum(cur_cum,data[i],k);
            }
        }
        return cum[num_of_elements][max_k];
    }
}

//The same algorithm but using fenwick trees
namespace smart_force
{

    ll cum_sum(ll idx,int k)
    {
        if(k==0) return 1;
        ll sum{0};
        while(idx>=1)
        {
            sum += cum[idx][k];
            idx -= idx & -idx;
        }
        return sum;
    }

    void cum_add(ll val,ll idx,int k)
    {
        while(idx<=num_of_elements)
        {
            cum[idx][k] += val;
            idx += idx & -idx;
        }
    }

    ll run()
    {
        for(ll i{1};i<=num_of_elements;i++)
        {
            for(int k{1};k<=max_k;k++)
            {
                ll cur_cum = cum_sum(data[i]-1,k-1);
                cum_add(cur_cum,data[i],k);
            }
        }
        return cum_sum(num_of_elements, max_k);
    }
}

void bench(std::function<ll()> fnc,
        const string& name)
{
    //Make sure the cum table is clear
    for(ll i{0};i<=num_of_elements;i++)
        for(int k{0};k<=max_k;k++)
            cum[i][k] = 0;
    //Ok, let's go..
    cout<<"Running: "<<name<<endl;
    auto start = chrono::high_resolution_clock::now();
    auto ret_value = fnc();
    auto stop = chrono::high_resolution_clock::now();
    cout<<"Execution time: "<<chrono::duration_cast<chrono::milliseconds>(stop-start).count()<<"ms\n";
    cout<<"Result: "<<ret_value<<endl;
}


int main()
{
    cout.sync_with_stdio(false);

    data.resize(10000);
    //Note, data starts with 0, but this is ignored.
    //the allowed numbers are 1...n,
    std::iota(data.begin(),data.end(),0);
    num_of_elements = data.size()-1;
    max_k = 10;

    bench(brute_force::run, "Brute");
    bench(smart_force::run, "Smart");
}
