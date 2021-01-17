#pragma once
#include <vector>
#include "Node.h"

template<typename Key, typename Value>
class HashTable
{
private:
	static int TABLE_SIZE;
	std::vector<Node<Key, Value>*> table;
	static unsigned long hashFunction(const Key& key);
public:
	HashTable();
	bool get(const Key& key, Value& value);
	void put(const Key& key, const Value& value);
	void remove(const Key& key);
	~HashTable();
};

