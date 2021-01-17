#ifndef HEAP
#define HEAP

class Heap
{
private:
    template <typename T>
    static void sink(T *, int, int);
    template <typename T>
    static bool less(T *, int, int);
    template <typename T>
    static void exch(T *, int, int);

public:
    template <typename T>
    static void sort(T *, int);
};

#endif
