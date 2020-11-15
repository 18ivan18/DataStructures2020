#include <iostream>
#include "SkipList.cpp"

int main()
{
	SkipList<int> list;
	list.insertSorted(4);
	list.insertSorted(5);
	list.insertSorted(6);
	list.insertSorted(8);
	list.insertSorted(9);
	list.insertSorted(14);
	list.insertSorted(17);
	list.insertSorted(20);

	list.speedUp();
	
	std::cout << "element 4 pos:" << list.find(4, [](const int a,const int b) {return a < b; }) << '\n';
	std::cout << "element 8 pos:" << list.find(8, [](const int a, const int b) {return a < b; }) << '\n';
	std::cout << "element 20 pos:" << list.find(20, [](const int a, const int b) {return a < b; }) << '\n';
	return 0;
}