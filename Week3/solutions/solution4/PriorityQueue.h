#pragma once
#include <queue>
template<typename T>
class PriorityQueue
{
private:
	std::queue<T> low_priority;
	std::queue<T> normal_priority;
	std::queue<T> high_priority;
public:
	enum Priority {LOW, NORMAL, HIGH};
	PriorityQueue();
	void push(const T& element, const Priority pr = NORMAL);
	void pop();
	T front();
	bool isEmpty() const;
	void print() const;
};

