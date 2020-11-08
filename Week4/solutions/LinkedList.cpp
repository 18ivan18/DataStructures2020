#include "LinkedList.h"
#include <stack>

template <typename T>
struct LinkedList<T>::Node
{
    Node *next;
    T item;
};

template <typename T>
class LinkedList<T>::Iterator
{
public:
    Iterator() noexcept : currentNode(head) {}

    Iterator(const Node *node) noexcept : currentNode(node) {}

    Iterator &operator=(Node *node)
    {
        this->currentNode = node;
        return *this;
    }

    // Prefix ++ overload
    Iterator &operator++()
    {
        if (currentNode)
            currentNode = currentNode->next;
        return *this;
    }

    // Postfix ++ overload
    Iterator operator++(int)
    {
        Iterator iterator = *this;
        ++*this;
        return iterator;
    }

    bool operator!=(const Iterator &iterator)
    {
        return currentNode != iterator.currentNode;
    }

    int operator*()
    {
        return currentNode->item;
    }

private:
    const Node *currentNode;
};

template <typename T>
LinkedList<T>::LinkedList() : head(nullptr)
{
}

template <typename T>
LinkedList<T>::~LinkedList()
{
    deleteList();
}

template <typename T>
void LinkedList<T>::deleteList()
{
    Node *temp;
    while (head != nullptr)
    {
        temp = head;
        head = head->next;
        delete temp;
    }
}

template <typename T>
void LinkedList<T>::push(const T &elem)
{
    Node *newItem = new Node();
    newItem->item = elem;
    newItem->next = head;
    head = newItem;
}

// О(n)
template <typename T>
int LinkedList<T>::count() const
{
    int cnt = 0;
    Node *temp = head;
    while (temp != nullptr)
    {
        cnt++;
        temp = temp->next;
    }
    return cnt;
}

// О(n)
template <typename T>
T LinkedList<T>::getNth(int n) const
{
    int cnt = 0;
    Node *temp = head;
    while (cnt < n)
    {
        cnt++;
        temp = temp->next;
    }
    return temp->item;
}

template <typename T>
T LinkedList<T>::pop()
{
    Node *temp = head;
    T result = head->item;
    head = head->next;
    delete temp;
    return result;
}

template <typename T>
T LinkedList<T>::popBack()
{
    Node *temp = head;
    while (temp != nullptr && temp->next != nullptr && temp->next->next != nullptr)
    {
        temp = temp->next;
    }
    T result = temp->next->item;
    delete temp->next;
    temp->next = nullptr;
    return result;
}

template <typename T>
void LinkedList<T>::insertNth(T item, int n)
{
    if (n == 0)
    {
        push(item);
        return;
    }
    int cnt = 0;
    Node *temp = head;
    while (cnt < n - 1)
    {
        cnt++;
        temp = temp->next;
    }
    Node *newNode = new Node();
    newNode->item = item;
    newNode->next = temp->next;
    temp->next = newNode;
}

template <typename T>
void LinkedList<T>::reverse()
{
    Node *result = nullptr;
    Node *current = head;
    Node *next;

    while (current != nullptr)
    {
        next = current->next;
        current->next = result;
        result = current;

        current = next;
    }

    head = result;
}

template <typename T>
void LinkedList<T>::append(LinkedList &ll)
{
    Node *temp = head, *prev;
    while (temp != nullptr)
    {
        prev = temp;
        temp = temp->next;
    }
    Node *appendHead = ll.head;
    while (appendHead != nullptr)
    {
        prev->next = appendHead;
        prev = prev->next;
        appendHead = appendHead->next;
    }
    ll.head = nullptr;
}

template <typename T>
T LinkedList<T>::middle()
{
    Node *slow = head, *fast = head;
    while (fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next;
        if (fast)
        {
            fast = fast->next;
        }
    }
    return slow->item;
}

template <typename T>
void LinkedList<T>::insert(const T &item)
{
    Node *temp = head;
    while (temp != nullptr && temp->next != nullptr)
    {
        temp = temp->next;
    }
    Node *newNode = new Node();
    newNode->next = nullptr;
    newNode->item = item;
    if (head == nullptr)
    {
        head = newNode;
        return;
    }
    temp->next = newNode;
}

// doesn't work
template <typename T>
bool LinkedList<T>::detectCycle()
{
    Node *fast = head, *slow = head;
    while (fast != nullptr)
    {
        slow = slow->next;
        fast = fast->next;
        if (fast)
        {
            fast = fast->next;
        }
        if (fast == slow)
        {
            return true;
        }
    }
    return false;
}

// doesn't work
template <typename T>
void LinkedList<T>::createCycle()
{
    Node *slow = head, *fast = head;
    while (fast->next)
    {
        slow = slow->next;
        fast = fast->next;
        if (fast)
        {
            fast = fast->next;
        }
    }
    fast->next = slow;
}

template <typename T>
bool LinkedList<T>::isPalindrom()
{
    Node *slow = head;
    std::stack<Node *> st;
    while (slow)
    {
        st.push(slow);
        slow = slow->next;
    }
    slow = head;
    while (slow)
    {
        T i = st.top()->item;
        st.pop();
        if (slow->item != i)
        {
            return false;
        }
        slow = slow->next;
    }
    return true;
}