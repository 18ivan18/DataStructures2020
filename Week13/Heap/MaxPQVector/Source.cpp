#include <iostream>
#include <fstream>
#include "MaxPQ.cpp"
#include "Iterator.cpp"

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
	
	/*
	for(TYPE element : pq)
	{
        std::cout << element << ' ';
	}
    
    std::cout << '\n';
    */
    return 0;
}