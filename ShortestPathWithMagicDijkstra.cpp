#include <limits>
#include <vector>
#include <iostream>
#include <string>

namespace pr_queue
{

//Tune the heap size to fit your needs
constexpr int default_heap_size{ 1024 };
constexpr int undefined_weight{ std::numeric_limits<int>::max() / 2 - 1 };


struct item{
    int vertex {0};
    //Path weight from the source to this vertex
    double weight { undefined_weight };
    int used_potions;
    item() = default;
    item(int v,double w, int k) :
       vertex{v} , weight{w}, 
       used_potions{k}{}
};


constexpr int gleft(int p) { return p*2; }
constexpr int gright(int p) { return p*2 + 1; }
constexpr int gparent(int p) { return p > 1 ? p/2 : 1; }

class pqueue{
    int min_heap_tail;
    std::vector<item> min_heap;
    void increse_key(int position);
    void min_heapify(int pos);
    int insert(item new_item);
public:
    pqueue();
    int insert(int vertex,double weight,int potions);
    void change(int vertex,int potions,double new_weight);
    item extract();
    int size();

public://Utility stuff
    void print();
};

pqueue::pqueue() :
    min_heap(default_heap_size), min_heap_tail{1} {
}

//Check whether the entry at index 'position'
//is still satisfying the min heap quality.
void pqueue::increse_key(int position){
    while(position>1){
        int parent = gparent(position);
        if(min_heap[parent].weight > min_heap[position].weight){
            std::swap(min_heap[parent],min_heap[position]);
            position = parent;
        }
        else break;
    }
}

void pqueue::min_heapify(int pos){
    if(pos>=min_heap_tail) return;
    int m = pos;
    if( min_heap[gleft(pos)].weight < min_heap[gright(pos)].weight )
        m = gleft(pos);
    else
        m = gright(pos);
    if(min_heap[m].weight <= min_heap[pos].weight){
        std::swap(min_heap[pos],min_heap[m]);
        min_heapify(m);
    }
}

int pqueue::insert(int vertex, double weight, int potions){
    return insert(item(vertex, weight, potions));
}

int pqueue::insert(item new_item){
    min_heap[min_heap_tail] = new_item;
    increse_key(min_heap_tail);
    return min_heap_tail++;
}

item pqueue::extract(){
    if(min_heap_tail == 1){
        return item();
    }
    item min_item = min_heap[1];
    min_heap[1].weight = undefined_weight;
    min_heapify(1);
    --min_heap_tail;
    return min_item;
}

void pqueue::change(int vertex,int potions, double new_weight){
    //This need to be optimized
    bool found{false};
    for(int i{1};i<min_heap_tail;i++){
        if(min_heap[i].vertex==vertex && min_heap[i].used_potions==potions){
            found = true;
            if(new_weight > min_heap[i].weight){
                min_heap[i].weight = new_weight;
                min_heapify(i);
            }else{
                min_heap[i].weight = new_weight;
                increse_key(i);
            }
            break;
        }
    }
    if(!found){
        insert(vertex,new_weight,potions);
    }
}

int pqueue::size(){
    return min_heap_tail - 1;
}

}

double mp[51][51];

double shortest_pah(int s,int d,int k,int V)
{
	pr_queue::pqueue Q;
	std::vector<double> weight(V,pr_queue::undefined_weight);
	weight[s] = 0;
	Q.insert(s,0,0);
	for(int i{1};i<V;i++)
	{
		Q.insert(i,pr_queue::undefined_weight,0);
	}
	while(Q.size()>0)
	{
		pr_queue::item cur = Q.extract();
//		std::cout<<"@:"<<cur.vertex<<","<<cur.weight<<","<<cur.used_potions<<","<<weight[cur.vertex]<<std::endl;
		for(int i{0};i<V;i++)
		{
			if(i==cur.vertex || mp[cur.vertex][i]==0) continue;
			if(weight[i] > (mp[cur.vertex][i] + cur.weight))
			{
				weight[i] = mp[cur.vertex][i] + cur.weight;
				Q.change(i,cur.used_potions,weight[i]);
			}
			if(cur.used_potions < k && (weight[i] > (double(mp[cur.vertex][i])/2.0 + cur.weight)))
			{
				weight[i] = double(mp[cur.vertex][i])/2.0 + cur.weight;
				Q.change(i,cur.used_potions + 1,weight[i]);
			}
		}
	}
	return weight[d];
}

void init(std::vector<std::string>& d)
{
	for(int i{0};i<d.size();i++)
	{
		for(int j{0};j<d[i].size();j++)
		{
			mp[i][j] = d[i][j]-'0';
			std::cout<<mp[i][j];
		}
		std::cout<<std::endl;
	}
}

int main()
{
	std::vector<std::string> s1 = {"094", "904", "440"};
	std::vector<std::string> s2 = {"076237", "708937", "680641", "296059", "334508", "771980"};
	std::vector<std::string> s3 = {"09247266124", "90123790803", "21068509704", "42607851294", "73870470851", "27584008427", "69057008220", "60910880035", "18728420068", "20095223606", "43441705860"};
	init(s2);
	std::cout<<shortest_pah(0,1,2,s2.size())<<std::endl;
}
