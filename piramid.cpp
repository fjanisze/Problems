#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

namespace{
    map<int,vector<string>> data;
    string top,bott;
    string missing;
}

namespace{
    struct node{
       string word;
       vector<node*> child_word; 
        node() = default;
        node(string w): word{w}{}
    };
}

node* build_the_tree(string root_string){
    //cout<<"New root: "<<root_string<<endl;
    node* root = new node(root_string);
    int n = root_string.size() - 1;
    if(data.find(n)!=data.end()){
        //Seems that we have some potential child here
        for(auto s:data[n]){
            bool fail{false};
            for(auto c:s){
                if(root_string.find(c)==string::npos){
                    fail = true;
                    break;
                }
            }
            if(!fail)
            {
                //cout<<"child: "<<s<<endl;
                root->child_word.push_back(build_the_tree(s));
            }
            else{
              //  cout<<"not child: "<<s<<endl;
            }
        }
    }
    //cout<<"Completed: "<<root_string<<endl;
    return root;
}

int main() {
    int n;
    int case_n{1};
    while(std::cin)
    {
        cin >> n;
        if(n<0) break;
        int l{0};
        string layer;
        data.clear();
        vector<int> s_c;
        int c{-1};
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        string s;
        size_t ms{0};
        while(n--){
            std::getline(std::cin,s);
            if(s.back()=='\n'||s.back()=='\r') s.pop_back();
            if(s.empty()) continue;
            std::transform(s.begin(), s.end(), s.begin(), ::toupper);
            ms = max(ms,s.size());
            data[s.size()].push_back(s);
        }
        data[s.size()].push_back(s);
   /*     for(auto& e:data){
            cout<<"size: "<<e.first<<" : ";
            for(auto s:e.second)
                cout<<s<<",";
            cout<<endl;
        }*/
        vector<node*> heads;
        for(auto s:data[ms]){
            cout<<"NEW HEAD: "<<s<<endl;
            node* head = build_the_tree(s);
            heads.push_back(head);
        }
        int t;
        cin >> t;
        //cout<<"T: "<<t<<endl;
        cout<<"Case "<<case_n<<":"<<endl;
        while(t--){
            cin>>top>>bott;
            if(top.back()=='\n'||top.back()=='\r') top.pop_back();
            if(bott.back()=='\n'||bott.back()=='\r') bott.pop_back();
            std::transform(top.begin(), top.end(), top.begin(), ::toupper);
            std::transform(bott.begin(), bott.end(), bott.begin(), ::toupper);
            if(top.size()>bott.size()){
                swap(top,bott);
            }
        }
        n = -1;
        ++case_n;
    }
    return 0;
}

