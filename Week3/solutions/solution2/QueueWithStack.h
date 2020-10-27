#pragma once
#include <stack>

template<typename T>
class QueueWithStack
{
private:
	std::stack<T> top_stack;
	std::stack<T> pop_stack;
public:
	QueueWithStack();
	bool isEmpty() const;
	size_t size() const;
	void push(const T& element);
	void pop();
	T front();
};
