//http://codeforces.com/contest/706/problem/D
#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <unordered_map>
#include <memory>
using namespace std;


#define printv(data) for(auto& e:data) cout<<e<<","; cout<<endl;
#define sortv(data) std::sort(data.begin(),data.end());
#define rsortv(data) std::sort(data.rbegin(),data.rend());

#define fori(start,end) for(size_t i{start};i<=end;i++)
#define forj(start,end) for(size_t j{start};j<=end;j++)
#define rofi(start,end) for(size_t i{start};i>end;i--)

#define foralli(data) fori(0,data.size())

using ll = long long;
using ld = long double;
using pll = std::pair<ll,ll>;
using vpll = std::vector<pll>;
using vll = std::vector<ll>;

constexpr ll BIGLL{ std::numeric_limits<ll>::max() };
constexpr ld BIGLD{ std::numeric_limits<ld>::max() };
constexpr ll LL10{ 10000000000 + 1 };
constexpr ld pi = 3.141592653589793238462643383279502884;

template<typename t,typename t2>
auto min(t&& a,t2&& b) -> decltype(a+b){ return a < b ? a : b; }

template<typename t,typename t2>
auto max(t&& a,t2&& b) -> decltype(a+b){ return a > b ? a : b; }

template<typename N>
N multimax_impl(N cur,N last)
{   return max(cur,last);   }

template<typename N,typename...VALS>
N multimax_impl(N cur,N n,VALS...vals)
{   return multimax_impl(max(cur,n),vals...);   }

template<typename N,typename...VALS>
N multimax(N f,VALS...values)
{   return multimax_impl(std::numeric_limits<N>::min(),f,values...); }

template<typename T>
T pow(T n,T e){
    T r{1};
    while(e--)
        r*=n;
    return r;
}

ll prime_factors(ll n,std::vector<ll>& data){
    while(n%2==0){data.emplace_back(2);n/=2;}
    for(ll i{3};i<=sqrt(n);i+=2){while(n%i==0){data.emplace_back(i);n/=i;}}
    if(n>2) data.emplace_back(n);
    return data.size();
}

#define get(var_name) ll var_name{0}; cin >> var_name;
#define gets(var_name) std::string var_name; cin >> var_name;
#define readv(start,end,vec_name) std::vector<ll> vec_name(end); for(size_t i{start};i<end;i++) cin>>vec_name[i];
#define getpll(llp) std::cin>>llp.first>>llp.second;


//specific for codeforces
#ifndef ONLINE_JUDGE
#define Log(...) fprintf (stdout, __VA_ARGS__);
#define LogN(num) fprintf (stdout, "@: %l64d\n", num);
#define LogS(str) fpringf (stdout, "@: %s\n", str.c_str());
#else
#define Log(...)
#define LogN(num)
#define LogS(str)
#endif

using num_type = long;
struct trie_node;

using node_ptr = std::shared_ptr<trie_node>;

struct trie_node
{
    node_ptr child[2];
    int      count{ 0 };
    num_type num;
};

class num_trie
{
    node_ptr root;
    int remove_bit;
    int remove_num;
    void remove_impl(node_ptr cur);
    void kill_empty_childs(node_ptr cur);
public:
    num_trie();
    void add(num_type num);
    void remove(num_type num);
    num_type find(num_type target);
};


num_trie::num_trie()
{
    root = std::make_shared<trie_node>();
}

void num_trie::add(num_type num)
{
    //Let's assume 32 bit numbers
    node_ptr current = root;
    for(int i{31};i>=0;--i)
    {
        bool bit = (num >> i) & 1;
        if(current->child[bit] == nullptr){
            current->child[bit] = std::make_shared<trie_node>();
        }
        ++current->count;
        current = current->child[bit];
    }
    ++current->count;
    current->num = num;
}

void num_trie::kill_empty_childs(node_ptr cur)
{
    if(cur->child[0] != nullptr && cur->child[0]->count == 0){
        cur->child[0] = nullptr;
    }
    if(cur->child[1] != nullptr && cur->child[1]->count == 0){
        cur->child[1] = nullptr;
    }
}

void num_trie::remove_impl(node_ptr cur)
{
    if(remove_bit >= 0){
        remove_impl(cur->child[(remove_num >> remove_bit--) & 1]);
    }
    else{
        cur->count = max(0, cur->count - 1);
        return;
    }
    kill_empty_childs(cur);
    cur->count = max(0, cur->count - 1);
}

void num_trie::remove(num_type num)
{
    remove_bit = 31;
    remove_num = num;
    remove_impl(root);
    kill_empty_childs(root);
}

num_type num_trie::find(num_type num)
{
    node_ptr current = root;
    for(int i{31};i>=0;--i)
    {
        bool bit = (num >> i) & 1;
        if(current->child[bit] == nullptr)
            bit ^= 1;
        current = current->child[bit];
    }
    return current->num;
}

int main()
{
    ios_base::sync_with_stdio(false);
    num_trie trie;
    trie.add(0);
    get(n);
    char op;
    std::size_t val;
    std::vector<num_type> ans;
    fori(1,n)
    {
        cin >> op ;
        cin >> val;
        switch(op){
        case '+':
            trie.add(val);
            break;
        case '-':
            trie.remove(val);
            break;
        case '?':
            ans.push_back(trie.find(~val) ^ val);
            break;
        default:
            break;
        }
    }
    for(auto e:ans)
        std::cout<<e<<std::endl;
    return 0;
}
