//http://codeforces.com/problemset/problem/639/B
#include <iostream>
#include <vector>
#include <memory>
#include <queue>
using namespace std;

struct node;

using node_ptr = shared_ptr<node>;

struct node
{
    int label{0};
    vector<node_ptr> childs;
    node(int lb):label{lb}{}
};

class bear_tree
{
    node_ptr root;
    bool impossible{false};
public:
    bear_tree(int n,int d,int h){
        if(n>2 && h < (d-h) || (n>=3 && (d==1 || d>2*h))){
            impossible = true;
            return;
        }
        int current_label{1};
        root = make_shared<node>(current_label++);
        node_ptr tmp = root;
        node_ptr prev_node;
        //Create a subtree of height h
        for(int i{0};i<h;i++)
        {
            //cout<<"Adding h. "<<current_label<<endl;
            node_ptr new_node = make_shared<node>(current_label++);
            tmp->childs.push_back(new_node);
            prev_node = tmp;
            tmp = new_node;
        }
        //Create another subtree with height d-h
        tmp = root;
        for(int i{0};i<(d-h);i++)
        {
            //cout<<"Adding d-h, label:"<<current_label<<", d-h:"<<d-h<<endl;
            node_ptr new_node = make_shared<node>(current_label++);
            tmp->childs.push_back(new_node);
            prev_node = tmp;
            tmp = new_node;
        }
        //cout<<"#:"<<current_label<<","<<n<<endl;
        if(current_label-1>n){
            impossible = true;
        }else{
            //We need to add some other nodes
            while(current_label<=n){
                node_ptr new_node = make_shared<node>(current_label++);
                prev_node->childs.push_back(new_node);
            }
        }
    }
    void print_result(){
        if(impossible){
            cout<<"-1\n";
        }else{
            queue<node_ptr> Q;
            Q.push(root);
            while(!Q.empty()){
                auto current = Q.front();
                Q.pop();
                for(auto e:current->childs){
                    Q.push(e);
                    cout<<current->label<<" "<<e->label<<endl;
                }
            }
        }
    }
};

int main()
{
    int n,d,h;
    cin >> n >> d >> h;
    bear_tree tree(n,d,h);
    tree.print_result();
}
