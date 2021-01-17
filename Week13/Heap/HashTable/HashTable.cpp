#include "HashTable.h"

template <typename Key, typename Value>
int HashTable<Key, Value>::TABLE_SIZE = 1024;

template <typename Key, typename Value>
unsigned long HashTable<Key, Value>::hashFunction(const Key& key)
{
	return static_cast<unsigned long>(key) % TABLE_SIZE;
}

template <typename Key, typename Value>
HashTable<Key, Value>::HashTable()
{
	table.resize(TABLE_SIZE);
}

template <typename Key, typename Value>
bool HashTable<Key, Value>::get(const Key& key, Value& value)
{
	unsigned long hashValue = hashFunction(key);
	Node<Key, Value>* bucket = table[hashValue];

	while(bucket != nullptr)
	{
		if(bucket->key == key)
		{
			value = bucket->value;
			return true;
		}
		bucket = bucket->next;
	}

	return false;
}

template <typename Key, typename Value>
void HashTable<Key, Value>::put(const Key& key, const Value& value)
{
	unsigned long hashValue = hashFunction(key);
	Node<Key, Value>* prev = nullptr;
	Node<Key, Value>* bucket = table[hashValue];

	while(bucket != nullptr && bucket->key != key)
	{
		prev = bucket;
		bucket = bucket->next;
	}

	//create new bucket
	if(bucket == nullptr)
	{
		bucket = new Node<Key, Value>{ key, value, nullptr };
		if(prev == nullptr)
		{
			table[hashValue] = bucket;
		}
		else
		{
			prev->next = bucket;
		}
	}
	else
	{
		bucket->value = value;
	}
}

template <typename Key, typename Value>
void HashTable<Key, Value>::remove(const Key& key)
{
	
}



