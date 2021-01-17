#ifndef MAX_PRIORITY_QUEUE
#define MAX_PRIORITY_QUEUE

// implementation insert (del max) max
// unordered array 1 N N
// ordered array N 1 1
// binary heap log N log N 1
// d-ary heap logd N d logd N 1
// Fibonacci 1 log N † 1
// impossible 1 1 1

//also
// Immutability of keys.
// ・Assumption: client does not change keys while they're on the PQ.
// ・Best practice: use immutable keys

template<typename T>
class Iterator;

template <typename T>
class MaxPQ
{
private:
    T* data;
    int capacity;
    int size;

    bool less(int, int);
    void exch(int, int);

    void swim(int);
    void sink(int);

    void resize(int);
    void copy(const MaxPQ& other);
    void del();

public:
    MaxPQ();
    MaxPQ(const MaxPQ& other);
    MaxPQ& operator=(const MaxPQ& other);
    ~MaxPQ();

    bool isEmpty();
    T delMax();
    void insert(T&);
    int getSize();
    T getMax();

    Iterator<T> begin();
    Iterator<T> end();
};

#endif
