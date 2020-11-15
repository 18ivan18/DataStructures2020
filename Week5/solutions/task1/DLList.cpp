#include "DLList.h"
#include <iostream>
#include <vector>

template<typename T>
DLList<T>::DLList() : first(nullptr), last(nullptr)
{
}

template<typename T>
bool DLList<T>::isEmpty() const
{
	return first == nullptr;
}

template<typename T>
size_t DLList<T>::size() const
{
	size_t result = 0;
	node* index = first;
	while(index != nullptr)
	{
		index = index->next;
		result++;
	}
	return result;
}

template<typename T>
T DLList<T>::front() const
{
	if(first != nullptr)
	{
		return first->data;
	}
	else
	{
		return T();
	}
}

template<typename T>
T DLList<T>::back() const
{
	if(last != nullptr)
	{
		return last->data;
	}
	else
	{
		return T();
	}
}

template<typename T>
void DLList<T>::assign(const size_t& n, const T& element)
{
	size_t counter = n;
	if(first == nullptr)
	{
		first = new node{ element, nullptr, nullptr };
		last = first;
		counter--;
	}
	
	node* index = first;
	while(counter != 0)
	{
		index->next = new node{ element, nullptr, index };
		index = index->next;
		if (counter == 1)
		{
			last = index;
		}
		counter--;
	}
}

template<typename T>
void DLList<T>::pushFront(const T& element)
{
	node* temp = first;
	first = new node{ element, temp, nullptr };
	if (temp != nullptr)
	{
		temp->prev = first;
	}
	else
	{
		last = first;
	}
}

template<typename T>
void DLList<T>::pushBack(const T& element)
{
	node* temp = last;
	last = new node{ element, nullptr, temp };
	if(temp != nullptr)
	{
		temp->next = last;
	}
	else
	{
		first = last;
	}
}

template<typename T>
void DLList<T>::popFront()
{
	if(first != nullptr)
	{
		node* save = first;
		first = first->next;
		delete save;
		first->prev = nullptr;
	}
}

template<typename T>
void DLList<T>::popBack()
{
	if (last != nullptr)
	{
		node* save = last;
		last = last->prev;
		delete save;
		last->next = nullptr;
	}
}

template<typename T>
void DLList<T>::insert(const size_t& position, const T& element)
{
	size_t currentPosition = 0;
	node* index = first;
	while(index && currentPosition != position)
	{
		index = index->next;
		currentPosition++;
	}
	if(index == nullptr)
	{
		pushBack(element);
	}
	else if(index->prev == nullptr)
	{
		pushFront(element);
	}
	else
	{
		node* save = new node{ element, index, index->prev };
		index->prev->next = save;
		index->prev = save;
	}
}

template<typename T>
void DLList<T>::erase(const size_t& position)
{
	size_t currentPosition = 0;
	node* index = first;
	while (index && currentPosition != position)
	{
		index = index->next;
		currentPosition++;
	}
	if(index != nullptr)
	{
		if(index->next == nullptr)
		{
			popBack();
		}
		else if(index->prev == nullptr)
		{
			popFront();
		}
		else
		{
			index->next->prev = index->prev;
			index->prev->next = index->next;
			delete index;
		}
	}
}

template<typename T>
void DLList<T>::clear()
{
	if(first != nullptr)
	{
		node* save;
		while(first != nullptr)
		{
			save = first;
			first = first->next;
			delete save;
		}
		last = nullptr;
	}
}

template<typename T>
void DLList<T>::unique()
{
	std::vector<T> used;
	node* index = first;
	size_t currentPosition = 0;
	
	while(index != nullptr)
	{
		if(std::find(used.begin(), used.end(), index->data) == used.end())
		{
			used.push_back(index->data);
			index = index->next;
		}
		else
		{
			if(index->next == nullptr)
			{
				popBack();
			}
			else
			{
				node* save = index;
				index->prev->next = index->next;
				index->next->prev = index->prev;
				index = index->next;
				delete save;
			}
		}
		currentPosition++;
	}
}

template<typename T>
void DLList<T>::reverse()
{
	node* index = last;
	node* save = first = last;
	while(index != nullptr)
	{
		save->next = index->prev;
		save->prev = index->next;
		index = index->prev;
		save = save->next;
	}
}

template<typename T>
void DLList<T>::removeIf(bool(*predicate)(T element))
{
	node* index = first;
	size_t counter = 0;

	while(index != nullptr)
	{
		if(predicate(index->data))
		{
			if (index->next == nullptr)
			{
				popBack();
			}
			else
			{
				node* save = index;
				index->prev->next = index->next;
				index->next->prev = index->prev;
				index = index->next;
				delete save;
			}
		}
		else
		{
			index = index->next;
			counter++;
		}	
	}
}

template<typename T>
void DLList<T>::map(T (*function)(T element))
{
	node* index = first;

	while(index != nullptr)
	{
		index->data = function(index->data);
		index = index->next;
	}
}

template<typename T>
void DLList<T>::print() const
{
	node* index = first;

	while(index != nullptr)
	{
		if(index->next == nullptr)
		{
			std::cout << index->data << '\n';
		}
		else
		{
			std::cout << index->data << "->";
		}
		index = index->next;
	}
}

template<typename T>
void DLList<T>::printReverse() const
{
	node* index = last;

	while (index != nullptr)
	{
		if (index->prev == nullptr)
		{
			std::cout << index->data << '\n';
		}
		else
		{
			std::cout << index->data << "->";
		}
		index = index->prev;
	}
}

template<typename T>
typename DLList<T>::DLListIterator DLList<T>::begin()
{
	return DLListIterator(first);
}

template<typename T>
typename DLList<T>::DLListIterator DLList<T>::end()
{
	return DLListIterator(nullptr);
}

template<typename T>
DLList<T>::DLListIterator::DLListIterator(node* pos) : currentPosition(pos)
{
}

template<typename T>
void DLList<T>::DLListIterator::operator++()
{
	currentPosition = currentPosition->next;
}

template<typename T>
T DLList<T>::DLListIterator::operator*() const
{
	return currentPosition->data;
}

template<typename T>
bool DLList<T>::DLListIterator::operator==(const DLListIterator& other) const
{
	node* first = this->currentPosition;
	node* second = other.currentPosition;
	while(first != nullptr && second != nullptr)
	{
		if(first->data != second->data)
		{
			return false;
		}
	}
	return first == nullptr && second == nullptr;
}

template<typename T>
bool DLList<T>::DLListIterator::operator!=(const DLListIterator& other) const
{
	return !(*this == other);
}
