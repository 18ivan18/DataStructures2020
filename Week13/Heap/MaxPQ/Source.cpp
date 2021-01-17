#include <iostream>
#include <fstream>
#include "MaxPQ.cpp"
#include "Iterator.cpp"
#include <string>

#define TYPE int

int main()
{
    std::ifstream in("input.txt");
	
    MaxPQ<TYPE>pq;

    TYPE x;
	
    while (!in.eof())
    {
        in >> x;
        pq.insert(x);
    }

	
    while(!pq.isEmpty())
    {
        std::cout << pq.getMax() << ' ';
        pq.delMax();
    }

    std::cout << '\n';
	

	//for(Iterator it = pq.begin(); it != pq.end(); ++it)
    //{
    //  *it
    //}
    //    B   E
	//    |   |
	//  1 5 3 7 *
	for(TYPE element : pq)
	{
        std::cout << element << ' ';
	}
    
    std::cout << '\n';
    
    return 0;
}