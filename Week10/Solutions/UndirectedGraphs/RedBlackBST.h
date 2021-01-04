#ifndef RED_BLACK_TREE
#define RED_BLACK_TREE
#include <list>

template <typename Key, typename Value>
class RedBlackBST
{
private:
    struct Node;

    Node *root;

    const bool RED = false;
    const bool BLACK = true;

    void deleteTree(Node *);
    int size(Node *);
    bool isRed(Node *);
    bool isEmpty();

    Node *put(Node *, const Key &, const Value &);

    Node *rotateLeft(Node *);
    Node *rotateRight(Node *);
    void flipColors(Node *);

    // Node *remove(Node *, const Key &);
    Node *balance(Node *);
    Node *moveRedLeft(Node *);
    Node *moveRedRight(Node *);

    void keys(Node *, std::list<Key> &) const;
    // Node *min(Node *);
    // Node *removeMin(Node *);

public:
    RedBlackBST();
    void put(const Key &, const Value &);
    Value *get(const Key &);
    bool contains(const Key &);
    std::list<Key> keys() const;
    // void remove(const Key &);
    // void removeMin();

    int size();
    ~RedBlackBST();
};

#endif
