//http://codeforces.com/contest/299/problem/C
#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

#define readi(start,end,data) for(size_t i{start};i<end;i++) cin>>data[i];
#define printv(data) for(auto& e:data) cout<<e<<","; cout<<endl;
#define sortv(data) std::sort(data.begin(),data.end());
#define rsortv(data) std::sort(data.rbegin(),data.rend());
#define fori(start,end) for(size_t i{start};i<end;i++)
#define forj(start,end) for(size_t j{start};j<end;j++)
constexpr size_t min(size_t a,size_t b){ return a<b?a:b; }
constexpr size_t max(size_t a,size_t b){ return a>b?a:b; }

using ll = long long;

int main()
{
    ios_base::sync_with_stdio(false);
    ll n;
    cin >> n;
    vector<char> first(2*n),second(2*n);
    stack<ll> common_one;
    stack<ll> yaro_noncommon,
        andre_noncommon;
    n*=2;
    vector<bool> used(n,false);
    readi(0,n,first);
    char ch;
    const char one = '1';
    const char zero = '0';
    fori(0,n){
        cin>>ch;
        if(ch==one && first[i]==ch){
            common_one.push(i);
        }
        second[i] = ch;

        if(first[i]==one && second[i]==zero){
            yaro_noncommon.push(i);
        }
        if(second[i]==one && first[i]==zero){
            andre_noncommon.push(i);
        }

    }

    //cout<<common_one.size()<<" "<<yaro_noncommon.size()<<" "<<andre_noncommon.size()<<endl;

    bool yaro{true};
    ll yaro_one{0},andre_one{0};
    while(!common_one.empty()){
        ll i = common_one.top();
        common_one.pop();
        if(!used[i])
        {
            if(yaro){
                yaro_one++;
                first[i] = 'x';
                second[i] = 'x';
            }else{
                andre_one++;
                second[i] = 'x';
                first[i] = 'x';
            }
        }
        used[i] = true;
        yaro ^= 1;
    }

    //cout<<"Next turn: "<<yaro<<endl;

    while(!andre_noncommon.empty()||!yaro_noncommon.empty()){
        if(yaro){
            if(!yaro_noncommon.empty()){
                while(!yaro_noncommon.empty()){
                    ll i = yaro_noncommon.top();
                    yaro_noncommon.pop();
                    //cout<<"1Yaro want to use: "<<i<<endl;
                    if(!used[i]){
                        used[i] = true;
                        first[i] = 'x';
                        ++yaro_one;
                        break;
                    }
                }
            }else{
                while(!andre_noncommon.empty())
                {
                    ll i = andre_noncommon.top();
                    //cout<<"2Yaro want to use: "<<i<<endl;
                    andre_noncommon.pop();
                    if(!used[i]){
                        used[i] = true;
                        second[i] = 'x';
                        break;
                    }
                }
            }
        }else{
            if(!andre_noncommon.empty()){
                while(!andre_noncommon.empty())
                {
                    ll i = andre_noncommon.top();
                    //cout<<"1Andre want to use: "<<i<<endl;
                    andre_noncommon.pop();
                    if(!used[i]){
                        used[i] = true;
                        second[i] = 'x';
                        ++andre_one;
                        break;
                    }
                }
            }else{
                while(!yaro_noncommon.empty())
                {
                    ll i = yaro_noncommon.top();
                    yaro_noncommon.pop();
                    //cout<<"2Andre want to use: "<<i<<endl;
                    if(!used[i]){
                        used[i] = true;
                        first[i] = 'x';
                        break;
                    }
                }
            }
        }
        yaro ^= 1;
    }
  /*  cout<<yaro_one<<" ";
    for(auto e:first)
        cout<<e;
    cout<<endl;

    cout<<andre_one<<" ";
    for(auto e:second)
        cout<<e;
    cout<<endl;*/
    if(yaro_one==andre_one){
        cout<<"Draw\n";
    }else if(yaro_one>andre_one){
        cout<<"First\n";
    }else{
        cout<<"Second\n";
    }
    return 0;
}
