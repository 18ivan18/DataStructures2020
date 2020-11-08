#ifndef LINKED_LST
#define LINKED_LST

template <typename T>
class LinkedList
{
private:
    struct Node;
    class Iterator;

    Node *head;

    void deleteList();

public:
    LinkedList();
    LinkedList(const LinkedList &) = delete;
    LinkedList &operator=(const LinkedList &) = delete;

    // Root of LinkedList wrapped in Iterator type
    Iterator begin()
    {
        return Iterator(head);
    }

    // End of LInkedList wrapped in Iterator type
    Iterator end()
    {
        return Iterator(nullptr);
    }

    void push(const T &);
    int count() const;
    // index n or nth doesn't matter
    T getNth(int) const;
    T pop();
    T popBack();
    void insertNth(T, int);
    void insert(const T &);
    void reverse();
    void append(LinkedList &);
    bool isPalindrom();
    bool detectCycle();
    void createCycle();
    T middle();
    ~LinkedList();
};

#endif
