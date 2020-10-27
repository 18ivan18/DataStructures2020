#include "PriorityQueue.cpp"

int main()
{
	PriorityQueue<double> myQ;
	myQ.push(14.5);
	myQ.push(33.3, PriorityQueue<double>::HIGH);
	myQ.push(-5, PriorityQueue<double>::LOW);
	myQ.push(18, PriorityQueue<double>::LOW);
	myQ.push(42, PriorityQueue<double>::HIGH);
	myQ.push(-102, PriorityQueue<double>::LOW);
	myQ.push(1, PriorityQueue<double>::NORMAL);
	myQ.push(-11);
	myQ.push(13, PriorityQueue<double>::HIGH);

	std::cout << "Front: " << myQ.front() << "\n";
	myQ.print();

	myQ.pop();
	myQ.pop();
	myQ.pop();
	myQ.pop();
	myQ.print();

	return 0;
}
