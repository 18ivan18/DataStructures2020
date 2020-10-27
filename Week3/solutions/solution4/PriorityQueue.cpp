#include "PriorityQueue.h"
#include <iostream>

template <typename T>
PriorityQueue<T>::PriorityQueue()
{
	
}

template <typename T>
void PriorityQueue<T>::push(const T& element, const Priority pr)
{
	switch (pr)
	{
	case LOW: low_priority.push(element);break;
	case NORMAL: normal_priority.push(element); break;
	case HIGH: high_priority.push(element); break;
	}
}

template <typename T>
void PriorityQueue<T>::pop()
{
	if(!high_priority.empty())
	{
		high_priority.pop();
	}
	else if(!normal_priority.empty())
	{
		normal_priority.pop();
	}
	else
	{
		low_priority.pop();
	}
}

template <typename T>
T PriorityQueue<T>::front()
{
	if (!high_priority.empty())
	{
		return high_priority.front();
	}

	if (!normal_priority.empty())
	{
		return normal_priority.front();
	}
	
	return low_priority.front();
}

template <typename T>
bool PriorityQueue<T>::isEmpty() const
{
	return high_priority.empty() && normal_priority.empty() && low_priority.empty();
}

template <typename T>
void PriorityQueue<T>::print() const
{
	if(!high_priority.empty())
	{
		std::queue<T> temp_high = high_priority;
		std::cout << "-----High-----\n";
		while (!temp_high.empty())
		{
			std::cout << temp_high.front() << " ";
			temp_high.pop();
		}
		std::cout << '\n';
	}
	if (!normal_priority.empty())
	{
		std::queue<T> temp_normal = normal_priority;
		std::cout << "-----Normal-----\n";
		while (!temp_normal.empty())
		{
			std::cout << temp_normal.front() << " ";
			temp_normal.pop();
		}
		std::cout << '\n';
	}
	if (!low_priority.empty())
	{
		std::queue<T> temp_low = low_priority;
		std::cout << "-----Low-----\n";
		while (!temp_low.empty())
		{
			std::cout << temp_low.front() << " ";
			temp_low.pop();
		}
		std::cout << '\n';
	}
}
