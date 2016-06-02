#include <iostream>
#include <memory>
#include <vector>
#include <initializer_list>
#include <functional>
using namespace std;

namespace segment_tree
{

using ll = long long;

template<typename comp_function>
class segment_tree
{
    std::vector<ll> segment_tree_data;
    std::vector<ll> input_data;
    std::size_t input_data_size;

    ll get_right_child(ll tree_position){
        return tree_position*2 + 1;
    }
    ll get_left_child(ll tree_position){
        return tree_position*2;
    }

    void build_tree(ll tree_position,
                    ll left,ll right);
    ll query_impl(ll left,ll right,
                  ll tree_left,ll tree_right,
                  ll tree_position);
public:
    segment_tree(std::vector<ll>& data) :
        input_data_size{data.size()}
    {
        segment_tree_data.assign(input_data_size * 4, 0);
        input_data = data;
        build_tree(1,0,input_data_size - 1);
    }
    ll query(ll left,ll right);
};

template<typename comp_function>
void segment_tree<comp_function>::build_tree(ll tree_position,
                              ll left, ll right)
{
    if(left==right){
        segment_tree_data[tree_position] = right;
    }else{
        build_tree(get_left_child(tree_position),
                   left,
                   (left + right)/2);

        build_tree(get_right_child(tree_position),
                   (right + left)/2 + 1,
                   right);

        ll index_1 = segment_tree_data[get_left_child(tree_position)],
           index_2 = segment_tree_data[get_right_child(tree_position)];

        segment_tree_data[tree_position] = (comp_function()(input_data[index_1],input_data[index_2]))?index_1:index_2;
    }
}

template<typename comp_function>
ll segment_tree<comp_function>::query_impl(ll left, ll right,
                            ll tree_left, ll tree_right,
                            ll tree_position)
{
    if(left > tree_right || right < tree_left)
        return -1; //We are out of position
    else if(left <= tree_left && right >= tree_right)
        return segment_tree_data[tree_position]; //Ok, we're in range

    ll index_1 = query_impl(left,right,
                            tree_left,
                            (tree_left + tree_right)/2,
                            get_left_child(tree_position));

    ll index_2 = query_impl(left,right,
                            (tree_left + tree_right)/2 + 1,
                            tree_right,
                            get_right_child(tree_position));

    if(index_1 < 0) return index_2;
    if(index_2 < 0) return index_1;

    if(comp_function()(input_data[index_1],input_data[index_2]))
        return index_1;
    return index_2;
}

template<typename comp_function>
ll segment_tree<comp_function>::query(ll left,ll right)
{
    return query_impl(left,right,0,input_data_size - 1,1);
}

}

using ll = long long;

std::vector<ll> test{5,4,5,1,3,11,2,55,4,8,4,3,6,5,5,7,88,5,7,6};

ll brute_force(ll left,ll right)
{
    ll min_v{0};
    while(left<=right){
        min_v = max(min_v,test[left++]);
    }
    return min_v;
}


int main()
{
    segment_tree::segment_tree<std::greater<ll>> tree(test);
    for(int i{0};i<test.size();i++){
        for(int j{i+1};j<test.size();j++)
        {
            if(test[tree.query(i,j)]!=brute_force(i,j)){
                cout<<"WRONG: "<<i<<","<<j<<" : "<<test[tree.query(i,j)]<<" "<<brute_force(i,j)<<endl;
            }
            else{
                cout<<"OK: "<<i<<","<<j<<" = "<<brute_force(i,j)<<endl;
            }
        }
    }
}
