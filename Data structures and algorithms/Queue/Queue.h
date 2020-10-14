#ifndef QUEUE
#define QUEUE

template <typename T>
class Queue
{
public:
    Queue();
    Queue(const Queue &);
    Queue &operator=(const Queue &);

    void enqueue(const T &);
    T dequeue();
    bool isEmpty();
    int size();
    ~Queue();
};

#endif