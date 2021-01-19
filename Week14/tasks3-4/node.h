#ifndef __NODE_H
#define __NODE_H

#include <sstream>

template <typename T>
struct TNode {
    T data;
    TNode *left, *mid, *right;
    TNode(T const& _data = T(), TNode *_left = nullptr, TNode *_mid = nullptr, TNode *_right = nullptr) :
        data(_data), left(_left), mid(_mid), right(_right) {}
};

using TONode = TNode<double>;
using TSNode = TNode<std::string>;

template <typename T>
std::string printTree(TNode<T>* t) {
  std::stringstream s;
  if (t != nullptr) {
    s << '(';
    s << t->data;
    s << printTree(t->left);
    s << printTree(t->mid);
    s << printTree(t->right);
    s << ')';
  }
  else
    s << '*';
  return s.str();
}

template <typename T>
void eraseTree(TNode<T>* t) {
  if (t != nullptr) {
    eraseTree(t->left);
    eraseTree(t->mid);
    eraseTree(t->right);
    delete t;
  }
}

#endif
