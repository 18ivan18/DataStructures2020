#include <iostream>
#include "Heap.cpp"

template <typename T>
void show(T *a, int n)
{
    for (int i = 0; i < n; i++)
    {
        std::cout << a[i] << " ";
    }
}

int main()
{
	
    int n;
    std::cin >> n;
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        std::cin >> arr[i];
    }
    Heap::sort(arr, n);
    show(arr, n);

    delete[] arr;
    return 0;
}