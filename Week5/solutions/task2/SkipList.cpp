#include "SkipList.h"
#include <cmath>

template<typename T>
void SkipList<T>::copy(const SkipList& other)
{
	if (other.head == nullptr)
	{
		this->head = nullptr;
	}
	else
	{
		node* otherIndex = other.head;
		node* index = this->head = otherIndex;
		node* prevSpeedup = nullptr;
		while (otherIndex->next != nullptr)
		{
			if (otherIndex->skip != nullptr && prevSpeedup == nullptr)
			{
				prevSpeedup = index;
			}
			else if (otherIndex->skip != nullptr && prevSpeedup != nullptr)
			{
				prevSpeedup->skip = index;
				prevSpeedup = index;
			}
			index->next = new node{ otherIndex->next->data, nullptr, nullptr };
			otherIndex = otherIndex->next;
		}
	}
}

template<typename T>
void SkipList<T>::erase()
{
	node* save = nullptr;
	while(head != nullptr)
	{
		save = head;
		head = head->next;
		delete save;
	}
}

template<typename T>
SkipList<T>::SkipList() : head(nullptr), length(0)
{
}

template<typename T>
SkipList<T>::SkipList(const SkipList& other)
{
	copy(other);
}

template<typename T>
SkipList<T>& SkipList<T>::operator=(const SkipList& other)
{
	if(*this->head != *other.head)
	{
		erase();
		copy(other);
	}
	return *this;
}

template<typename T>
size_t SkipList<T>::size() const
{
	return length;
}

template<typename T>
void SkipList<T>::insertSorted(const T& element)
{
	node* index = head;
	if(index == nullptr)
	{
		head = new node{ element, nullptr, nullptr };
		return;
	}
	while(index != nullptr && index->next != nullptr)
	{
		if(index->skip != nullptr)
		{
			index = index->skip;
		}
		else
		{
			index = index->next;
		}
	}
	index->next = new node{ element, nullptr, nullptr };
	length++;
}

template<typename T>
void SkipList<T>::speedUp() const
{
	int counter = 0;
	node* index = head;
	node* save = head;
	while(index != nullptr)
	{
		if (counter == round(sqrt(this->length)))
		{
			save->skip = index;
			save = index;
			counter = 0;
			index = index->next;
		}
		else
		{
			counter++;
			index = index->next;
		}
	}
}

template<typename T>
int SkipList<T>::find(const T& element, bool (*comparator)(T a, T b))
{
	node* index = head;
	int counter = 0;
	
	while(index != nullptr)
	{
		if(index->data == element)
		{
			return counter;
		}
		if(index->skip != nullptr && comparator(index->next->data, element) && comparator(index->skip->data, element))
		{
			index = index->skip;
			counter += round(sqrt(length)) + 1;
		}
		else if (index->skip != nullptr && !comparator(index->next->data, element))
		{
			return -1;
		}
		else if (index->skip != nullptr && index->skip->data == element)
		{
			return counter += round(sqrt(length));
		}
		else
		{
			index = index->next;
			counter++;
		}
	}

	return -1;
}
