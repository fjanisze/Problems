//http://codeforces.com/contest/672/problem/C
#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <iomanip>
using namespace std;

#define printv(data) for(auto& e:data) cout<<e<<","; cout<<endl;
#define sortv(data) std::sort(data.begin(),data.end());
#define rsortv(data) std::sort(data.rbegin(),data.rend());

#define fori(start,end) for(size_t i{start};i<end;i++)
#define forj(start,end) for(size_t j{start};j<end;j++)

#define foralli(data) fori(0,data.size())

using ll = long long;
using ld = long double;
using vll = std::vector<ll>;

#define get(var_name) ll var_name{0}; cin >> var_name;
#define gets(var_name) std::string var_name; cin >> var_name;
#define readv(start,end,vec_name) std::vector<ll> vec_name(end); for(size_t i{start};i<end;i++) cin>>vec_name[i];

constexpr ll BIGLL{ std::numeric_limits<ll>::max() };
constexpr ld BIGLD{ std::numeric_limits<ld>::max() };
constexpr ll LL10{ 10000000000 + 1 };

long double get_d(pair<ll,ll>& a,pair<ll,ll>& b)
{
    ll x = abs(a.first - b.first),y = abs(a.second-b.second);
    return std::sqrt(x*x+y*y);
}

ld dist[4][100001];

int main()
{
    ios_base::sync_with_stdio(false);
    pair<ll,ll> bin;
    pair<ll,ll> a,b;
    cin >> a.first >> a.second >> b.first >> b.second >> bin.first >> bin.second;
    get(n);
    vector<pair<ll,ll>> bottles(n);
    fori(0,n){
        cin >> bottles[i].first >> bottles[i].second;
    }
    ld tot_dist{0}, ans{BIGLD};
    dist[2][0] = BIGLD;
    fori(0,n){
        ld bot_dist = get_d(bin,bottles[i]);
        dist[0][i] = get_d(a,bottles[i]) - bot_dist;
        dist[1][i] = get_d(b,bottles[i]) - bot_dist;
        if(i>0){
            dist[2][i] = min(dist[2][i-1],dist[1][i-1]);
        }
        tot_dist += 2*bot_dist;
    }
    dist[3][n-1] = BIGLD;
    for(ll i{n-2};i>=0;i--)
    {
        dist[3][i] = min(dist[3][i+1],dist[1][i+1]);
    }
    ans = min(tot_dist + dist[3][0],tot_dist + dist[1][0]);;
    fori(0,n){
         ans = min(ans, std::min((ld)0.0, std::min(dist[2][i],dist[3][i]))+dist[0][i]+tot_dist);
    }
    cout<<setprecision(20)<<ans<<endl;
    return 0;
}
