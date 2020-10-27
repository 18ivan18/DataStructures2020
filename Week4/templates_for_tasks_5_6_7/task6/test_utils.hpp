#ifndef __TEST_UTILS
#define __TEST_UTILS

#include <sstream>
#include <vector>
#include "node.h"

template <class T>
node<T> *tolist (std::vector<T> v)
{
    if (v.size() == 0)
        return nullptr;
    
    node<T> *first = new node<T> (v[0],nullptr),
            *last = first;
    
    for (size_t i = 1; i < v.size(); i++)
    {
        last->next = new node<T> (v[i],nullptr);
        last = last->next;
    }
    return first;
}

template <class T>
std::vector<T> tovector(node<T> *first)
{
    std::vector<T> res;
    while (first != nullptr)
    {
        res.push_back (first->data);
        first = first->next;
    }
    return res;
}

namespace doctest
{
template <typename T>
struct StringMaker<std::vector<T>>
{
    static String convert(const std::vector<T>& v) {
        std::ostringstream oss;

		oss << "{ ";
		for (auto el : v)
		{
			oss << el << " ";
		}
		oss << "}";

		return oss.str().c_str();
    }
};
}
#endif
