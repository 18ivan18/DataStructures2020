#include "MaxPQ.h"
#include <cassert>
#include <iostream>
const int INITIAL_CAPACITY = 2;
const int INITIAL_SIZE = 0;

template <typename T>
void MaxPQ<T>::copy(const MaxPQ& other)
{
    this->data = new T[other.capacity];

    for (int i = 0; i < other.size; i++)
    {
        this->data[i] = other.data[i];
    }
}

template <typename T>
MaxPQ<T>::MaxPQ() : size(INITIAL_SIZE), capacity(INITIAL_CAPACITY)
{
    this->data = new T[capacity];
}

template <typename T>
MaxPQ<T>::MaxPQ(const MaxPQ& other) : capacity(other.capacity), size(other.size)
{
    copy(other);
}

template <typename T>
MaxPQ<T>& MaxPQ<T>::operator=(const MaxPQ& other)
{
	if(this != &other)
	{
        del();
        this->size = other.size;
        this->capacity = other.capacity;
        copy(other);
	}

    return *this;
}

template <typename T>
MaxPQ<T>::~MaxPQ()
{
    del();
}

template <typename T>
void MaxPQ<T>::del()
{
    delete[] data;
}

template <typename T>
bool MaxPQ<T>::isEmpty()
{
    return size == 0;
}

template <typename T>
int MaxPQ<T>::getSize()
{
    return size;
}

template <typename T>
T MaxPQ<T>::getMax()
{
    return data[1];
}

template <typename T>
Iterator<T> MaxPQ<T>::begin()
{
    return Iterator<T>(data, size, 0);
}

template <typename T>
Iterator<T> MaxPQ<T>::end()
{
    return Iterator <T>(data, size, size);
}

template <typename T>
T MaxPQ<T>::delMax()
{
    if (isEmpty())
    {
        throw "Queue empty.\n";
    }
    T max = data[1];
    exch(1, size);
    size--;
    sink(1);
    // delete data[size + 1];
    // if ((size > 0) && (size == (capacity - 1) / 4))
    //     resize(capacity / 2);
    return max;
}

template <typename T>
void MaxPQ<T>::insert(T& item)
{
    if (size == capacity - 1)
    {
        resize(capacity * 2);
    }
    size++;
    data[size] = item;
    swim(size);
}

template <typename T>
bool MaxPQ<T>::less(int i, int j)
{
    return data[i] < data[j];
}

template <typename T>
void MaxPQ<T>::exch(int i, int j)
{
    T t = data[i];
    data[i] = data[j];
    data[j] = t;
}

template <typename T>
void MaxPQ<T>::swim(int x)
{
	// x / 2 is parent, x is child
    while (x > 1 && less(x / 2, x))
    {
        exch(x / 2, x);
        x /= 2;
    }
}

template <typename T>
void MaxPQ<T>::sink(int x)
{
    while (2 * x <= size)
    {
        int j = 2 * x;
        if (j < size && less(j, j + 1))
        {
            j++;
        }
        if (!less(x, j))
        {
            break;
        }
        exch(j, x);
        x = j;
    }
}

template <typename T>
void MaxPQ<T>::resize(int newCapacity)
{
    assert(newCapacity > size);
    capacity = newCapacity;
    T* temp = new T[capacity];
    for (int i = 1; i <= size; i++)
    {
        temp[i] = data[i];
    }
    del();
    data = temp;
}