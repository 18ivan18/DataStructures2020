#include "RedBlackBST.h"

#define NODE typename RedBlackBST<Key, Value>::Node

template <typename Key, typename Value>
struct RedBlackBST<Key, Value>::Node
{
public:
    Node *left, *right;
    Key key;
    Value value;
    int size;
    // Color of parent link
    bool color;
    Node(Key, Value, bool, int);
};

template <typename Key, typename Value>
RedBlackBST<Key, Value>::Node::Node(Key key, Value value, bool color, int size)
{
    this->key = key;
    this->value = value;
    this->color = color;
    this->size = size;
    this->left = nullptr;
    this->right = nullptr;
}

template <typename Key, typename Value>
RedBlackBST<Key, Value>::RedBlackBST()
{
    root = nullptr;
}

template <typename Key, typename Value>
RedBlackBST<Key, Value>::~RedBlackBST()
{
    deleteTree(root);
}

template <typename Key, typename Value>
int RedBlackBST<Key, Value>::size()
{
    return size(root);
}

template <typename Key, typename Value>
bool RedBlackBST<Key, Value>::isRed(Node *x)
{
    if (x == nullptr)
    {
        return false;
    }
    return x->color == RED;
}

template <typename Key, typename Value>
bool RedBlackBST<Key, Value>::isEmpty()
{
    return root == nullptr;
}

template <typename Key, typename Value>
int RedBlackBST<Key, Value>::size(Node *x)
{
    if (x == nullptr)
    {
        return 0;
    }
    return x->size;
}

template <typename Key, typename Value>
void RedBlackBST<Key, Value>::deleteTree(Node *x)
{
    if (x == nullptr)
    {
        return;
    }
    deleteTree(x->left);
    deleteTree(x->right);
    delete x;
    x = nullptr;
}

template <typename Key, typename Value>
NODE *RedBlackBST<Key, Value>::rotateLeft(Node *h)
{
    Node *x = h->right;
    h->right = x->left;
    x->left = h;
    h->color = RED;
    x->color = h->color;
    x->size = h->size;
    h->size = 1 + size(h->left) + size(h->right);
    return x;
}

template <typename Key, typename Value>
NODE *RedBlackBST<Key, Value>::rotateRight(Node *h)
{
    Node *x = h->left;
    h->left = x->right;
    x->right = h;
    h->color = RED;
    x->color = h->color;
    x->size = h->size;
    h->size = 1 + size(h->left) + size(h->right);
    return x;
}

template <typename Key, typename Value>
void RedBlackBST<Key, Value>::flipColors(Node *x)
{
    // assert(!isRed(x));
    // assert(isRed(x->left));
    // assert(isRed(x->right));

    x->color = RED;
    x->left->color = BLACK;
    x->right->color = BLACK;
}

template <typename Key, typename Value>
void RedBlackBST<Key, Value>::put(const Key &key, const Value &value)
{
    root = put(root, key, value);
    root->color = BLACK;
}

// ・Right child red, left child black: rotate left.
// ・Left child, left-left grandchild red: rotate right.
// ・Both children red: flip colors.

template <typename Key, typename Value>
NODE *RedBlackBST<Key, Value>::put(Node *h, const Key &key, const Value &value)
{
    if (h == nullptr)
    {
        return new Node(key, value, RED, 1);
    }

    // Compare
    if (h->key < key)
    {
        h->right = put(h->right, key, value);
    }
    if (h->key > key)
    {
        h->left = put(h->left, key, value);
    }
    if (h->key == key)
    {
        h->value == value;
    }

    // Fix
    if (isRed(h->right) && !isRed(h->left))
    {
        h = rotateLeft(h);
    }
    if (isRed(h->left) && isRed(h->left->left))
    {
        h = rotateRight(h);
    }
    if (isRed(h->left) && isRed(h->right))
    {
        flipColors(h);
    }
    // Size
    h->size = 1 + size(h->left) + size(h->right);

    return h;
}

template <typename Key, typename Value>
Value *RedBlackBST<Key, Value>::get(const Key &key)
{
    Node *x = root;
    while (x != nullptr)
    {
        if (x->key == key)
        {
            return &x->value;
        }
        if (x->key < key)
        {
            x = x->right;
        }
        if (x->key > key)
        {
            x = x->left;
        }
    }
    return nullptr;
}

template <typename Key, typename Value>
bool RedBlackBST<Key, Value>::contains(const Key &key)
{
    return get(key) != nullptr;
}

/*
template <typename Key, typename Value>
void RedBlackBST<Key, Value>::remove(const Key &key)
{
    if (!isRed(root->left) && !isRed(root->right))
    {
        root->color = RED;
    }

    root = remove(root, key);
    if (!isEmpty())
    {
        root->color = BLACK;
    }
}

template <typename Key, typename Value>
NODE *RedBlackBST<Key, Value>::remove(Node *h, const Key &key)
{
    if (key < h->key)
    {
        if (!isRed(h->left) && !isRed(h->left->left))
        {
            h = moveRedLeft(h);
        }
        h->left = remove(h->left, key);
    }
    else
    {
        if (isRed(h->left))
        {
            h = rotateRight(h);
        }
        if (key == h->key && (h->right == nullptr))
        {
            return nullptr;
        }
        if (!isRed(h->right) && !isRed(h->right->left))
        {
            h = moveRedRight(h);
        }
        if (key == h->key)
        {
            Node *x = min(h->right);
            h->key = x->key;
            h->value = x->value;
            // h->val = get(h->right, min(h->right)->key);
            // h->key = min(h->right)->key;
            h->right = removeMin(h->right);
        }
        else
        {
            h->right = remove(h->right, key);
        }
    }
    return balance(h);
}
*/

template <typename Key, typename Value>
NODE *RedBlackBST<Key, Value>::balance(Node *h)
{
    if (isRed(h->right))
    {
        h = rotateLeft(h);
    }
    if (isRed(h->left) && isRed(h->left->left))
    {
        h = rotateRight(h);
    }
    if (isRed(h->left) && isRed(h->right))
    {
        flipColors(h);
    }

    h->size = size(h->left) + size(h->right) + 1;
    return h;
}

template <typename Key, typename Value>
NODE *RedBlackBST<Key, Value>::moveRedLeft(Node *h)
{

    flipColors(h);
    if (isRed(h->right->left))
    {
        h->right = rotateRight(h->right);
        h = rotateLeft(h);
        flipColors(h);
    }
    return h;
}

template <typename Key, typename Value>
NODE *RedBlackBST<Key, Value>::moveRedRight(Node *h)
{
    flipColors(h);
    if (isRed(h->left->left))
    {
        h = rotateRight(h);
        flipColors(h);
    }
    return h;
}

template <typename Key, typename Value>
std::list<Key> RedBlackBST<Key, Value>::keys() const
{
    std::list<Key> result;
    keys(root, result);
    return result;
}

template <typename Key, typename Value>
void RedBlackBST<Key, Value>::keys(Node *node, std::list<Key> &q) const
{
    if (!node)
    {
        return;
    }
    q.push(node.key);
    keys(node->left, q);
    keys(node->right, q);
}

/*
template <typename Key, typename Value>
NODE *RedBlackBST<Key, Value>::min(Node *x)
{
    // assert x != nullptr;
    if (x->left == nullptr)
    {
        return x;
    }
    return min(x->left);
}

template <typename Key, typename Value>
void RedBlackBST<Key, Value>::removeMin()
{
    if (isEmpty())
        throw "BST underflow";

    // If both children of root are black, set root to red
    if (!isRed(root->left) && !isRed(root->right))
    {
        root->color = RED;
    }

    root = removeMin(root);
    if (!isEmpty())
    {
        root->color = BLACK;
    }
    // assert check();
}

template <typename Key, typename Value>
NODE *RedBlackBST<Key, Value>::removeMin(Node *h)
{
    if (h->left == nullptr)
    {
        return nullptr;
    }

    if (!isRed(h->left) && !isRed(h->left->left))
    {
        h = moveRedLeft(h);
    }

    h->left = removeMin(h->left);
    return balance(h);
}*/