#pragma once

template<typename Key, typename Value>
struct Node
{
	Key key;
	Value value;
	Node* next;
};
