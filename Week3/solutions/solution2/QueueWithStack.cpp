#include "QueueWithStack.h"

#include <functional>

template <typename T>
QueueWithStack<T>::QueueWithStack()
{
}

template <typename T>
bool QueueWithStack<T>::isEmpty() const
{
	return top_stack.empty();
}

template <typename T>
size_t QueueWithStack<T>::size() const
{
	return top_stack.size();
}

template <typename T>
void QueueWithStack<T>::push(const T& element)
{
	top_stack.push(element);
}

template <typename T>
void QueueWithStack<T>::pop()
{
	while(!top_stack.empty())
	{
		pop_stack.push(top_stack.top());
		top_stack.pop();
	}
	pop_stack.pop();
	while(!pop_stack.empty())
	{
		top_stack.push(pop_stack.top());
		pop_stack.pop();
	}
}

template <typename T>
T QueueWithStack<T>::front()
{
	while (!top_stack.empty())
	{
		pop_stack.push(top_stack.top());
		top_stack.pop();
	}
	T temp = pop_stack.top();
	while (!pop_stack.empty())
	{
		top_stack.push(pop_stack.top());
		pop_stack.pop();
	}
	return temp;
}
