#include "priority.hpp"

namespace  pr_queue {

pqueue::pqueue() :
    max_heap(default_heap_size), max_heap_tail{1} {
}

//Check whether the entry at index 'position'
//is still satisfying the max heap quality.
void pqueue::increse_key(int position){
    while(position>1){
        int parent = gparent(position);
        if(max_heap[parent].weight < max_heap[position].weight){
            std::swap(max_heap[parent],max_heap[position]);
            position = parent;
        }
        else break;
    }
}

void pqueue::max_heapify(int pos){
    if(pos>=max_heap_tail) return;
    int m = pos;
    if( max_heap[gleft(pos)].weight > max_heap[gright(pos)].weight )
        m = gleft(pos);
    else
        m = gright(pos);
    if(max_heap[m].weight >= max_heap[pos].weight){
        std::swap(max_heap[pos],max_heap[m]);
        max_heapify(m);
    }
}

int pqueue::insert(int vertex, int weight){
    return insert(item(vertex, weight));
}

int pqueue::insert(item new_item){
    max_heap[max_heap_tail] = new_item;
    increse_key(max_heap_tail);
    return max_heap_tail++;
}

item pqueue::extract(){
    if(max_heap_tail == 1){
        return item();
    }
    item max_item = max_heap[1];
    max_heap[1].weight = undefined_weight;
    max_heapify(1);
    --max_heap_tail;
    return max_item;
}

void pqueue::change(int vertex, int new_weight){
    //This need to be optimized
    for(int i{1};i<max_heap_tail;i++){
        if(max_heap[i].vertex==vertex){
            if(new_weight < max_heap[i].weight){
                max_heap[i].weight = new_weight;
                max_heapify(i);
            }else{
                max_heap[i].weight = new_weight;
                increse_key(i);
            }
            break;
        }
    }
}

int pqueue::size(){
    return max_heap_tail - 1;
}

void pqueue::print()
{
    int p=2;
    for(int i{1};i<=max_heap_tail;i++){
        if( p == i ){
            std::cout<<" ";
            p*=2;
        }
        if(max_heap[i].weight == undefined_weight) continue;
        std::cout<<max_heap[i].weight<<",";
    }
    std::cout<<std::endl;
}
}
