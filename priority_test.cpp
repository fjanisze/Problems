#include "priority.hpp"
#include <iostream>
using namespace std;


int main()
{
	pr_queue::pqueue Q;
	Q.insert(1,10);
	Q.insert(2,5);
	Q.insert(5,1);
	Q.insert(7,30);
	Q.insert(6,2);
	Q.change(6,29);
	while(Q.size()>0)
	{
		pr_queue::item it = Q.extract();
		cout<<it.vertex<<" , "<<it.weight<<endl;
	}
}
