//Simple implementation of a priority queue used
//to implement graph algorithms

#include <limits>
#include <vector>
#include <iostream>

namespace pr_queue
{

//Tune the heap size to fit your needs
constexpr int default_heap_size{ 1024 };
constexpr int undefined_weight{ - 1 };

struct item{
    int vertex {0};
    //Path weight from the source to this vertex
    int weight { undefined_weight };
    item() = default;
    item(int v,int w) : vertex{v} , weight{w}{}
};

constexpr int gleft(int p) { return p*2; }
constexpr int gright(int p) { return p*2 + 1; }
constexpr int gparent(int p) { return p > 1 ? p/2 : 1; }

class pqueue{
    int max_heap_tail;
    std::vector<item> max_heap;
    void increse_key(int position);
    void max_heapify(int pos);
    int insert(item new_item);
public:
    pqueue();
    int insert(int vertex,int weight);
    void change(int vertex,int new_weight);
    item extract();
    int size();

public://Utility stuff
    void print();
};
}
