#include <iostream>
#include "QueueWithStack.cpp"

int main()
{
	QueueWithStack<int> myQueue;
	myQueue.push(5);
	myQueue.push(-17);
	myQueue.push(3);
	myQueue.push(42);
	myQueue.push(-69);
	myQueue.push(32);
	myQueue.push(19);
	myQueue.push(47);
	myQueue.push(120);
	
	while(!myQueue.isEmpty())
	{
		std::cout << myQueue.front() << ' ';
		myQueue.pop();
	}
	
	std::cout << '\n';
	return 0;
}
