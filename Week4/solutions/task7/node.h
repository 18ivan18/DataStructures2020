#ifndef __NODE_H
#define __NODE_H

template <typename T>
struct node {
  T data;
  node* next;

  node(T const& _data = T(), node* _next = nullptr) : data(_data), next(_next) {}
};

#endif