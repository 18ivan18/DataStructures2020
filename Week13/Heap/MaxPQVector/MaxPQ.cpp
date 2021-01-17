#include "MaxPQ.h"
const int INITIAL_CAPACITY = 2;
const int INITIAL_SIZE = 0;

template <typename T>
MaxPQ<T>::MaxPQ() : capacity(INITIAL_CAPACITY), size(INITIAL_SIZE)
{
    this->data.resize(INITIAL_CAPACITY);
}

template <typename T>
bool MaxPQ<T>::isEmpty() const
{
    return size == 0;
}

template <typename T>
int MaxPQ<T>::getSize() const
{
    return size;
}

template <typename T>
T MaxPQ<T>::getMax()
{
    return data[1];
}

template <typename T>
T MaxPQ<T>::delMax()
{
    if (isEmpty())
    {
        throw "Queue empty.\n";
    }
    T max = data[1];
    exch(1, size--);
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
        this->data.resize(capacity * 2);
        capacity *= 2;
    }
    data[++size] = item;
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
