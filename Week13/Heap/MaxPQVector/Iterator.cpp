#include "Iterator.h"
#include <iostream>
#include "Heap.cpp"

template <typename T>
void Iterator<T>::initData(const T* _data, const int& size)
{
	T* temp = new T[size + 2];

	for(int i = 0; i <= size; i++)
	{
		temp[i] = _data[i];
	}

	Heap::sort(temp, size + 1);

	for (int i = size; i >= 1; i--)
	{
		data.push_back(temp[i]);
	}

	delete[] temp;
}

template <typename T>
Iterator<T>::Iterator(T* _data, const int& _size, const int& _pos) : position(_pos)
{
	initData(_data, _size);
}

template <typename T>
Iterator<T>::Iterator(const Iterator& other) : data(other.data), position(other.position)
{
}

template <typename T>
Iterator<T>& Iterator<T>::operator=(const Iterator& other)
{
	if(this != &other)
	{
		data = other.data;
		position = other.position;
	}

	return *this;
}

template <typename T>
T Iterator<T>::operator*() const
{
	return data[position];
}

template <typename T>
void Iterator<T>::operator++()
{
	if(position < data.size())
	{
		position++;
	}
}

template <typename T>
bool Iterator<T>::operator==(const Iterator& other)
{
	if(data.size() != other.data.size() || position != other.position)
	{
		return false;
	}

	for(int i = 0; i < data.size(); i++)
	{
		if(data[i] != other.data[i])
		{
			return false;
		}
	}

	return true;
}

template <typename T>
bool Iterator<T>::operator!=(const Iterator& other)
{
	return !(*this == other);
}