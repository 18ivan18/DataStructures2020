#include <iostream>
#include "DLList.cpp"

int main()
{
	DLList<double> list;
	list.assign(10, 5);
	list.pushBack(3.14);
	list.pushBack(4.20);
	list.pushBack(1.21);
	list.pushFront(-5);
	list.pushFront(7.13);

	list.print();
	list.printReverse();

	std::cout << "size: " << list.size() << "\n\n";

	list.unique();

	list.print();
	list.printReverse();

	list.insert(2, 42);

	list.print();
	list.printReverse();

	list.removeIf([](double x) {return x > 10; });

	list.print();
	list.printReverse();

	list.map([](double x) {return x * x; });

	list.print();
	list.printReverse();

	std::cout << '\n';
	for(double element : list)
	{
		std::cout << element << " ";
	}
	std::cout << '\n';

	return 0;
}