#include "Heap.h"

//N is the size
template <typename T>
void Heap::sort(T *arr, int N)
{
    //heapify
    for (int k = N / 2; k >= 1; k--)
    {
        sink(arr, k, N);
    }
    // sort
    while (N > 1)
    {
        exch(arr, 1, N);
        sink(arr, 1, --N);
    }
}

template <typename T>
void Heap::sink(T *arr, int i, int N)
{
    while (2 * i <= N)
    {
        int j = 2 * i;
        if (j < N && less(arr, j, j + 1))
        {
            j++;
        }
        if (!less(arr, i, j))
            break;
        exch(arr, i, j);
        i = j;
    }
}

template <typename T>
bool Heap::less(T *arr, int i, int j)
{
    return arr[i - 1] < arr[j - 1];
}

template <typename T>
void Heap::exch(T *arr, int i, int j)
{
    T swap = arr[i - 1];
    arr[i - 1] = arr[j - 1];
    arr[j - 1] = swap;
}