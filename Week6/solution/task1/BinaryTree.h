#pragma once
#include <ostream>

template<typename Key, typename Value>
class BinaryTree
{
private:
	struct Node
	{
		std::pair<Key, Value> data;
		Node* left;
		Node* right;
	};
	Node* root;
	
	Node* constructorHelper(std::pair<Key, Value>* array, int size);
	void printHelper(Node* node, int spaces = 0) const;
	bool containsHelper(Node* node, const Key& element) const;
	size_t calculateHeightHelper(Node* node) const;
	Key sumLeavesHelper(Node* node) const;
	size_t countLeavesHelper(Node* node) const;
	Key reduceHelper(Node* node, Key (*operation)(Key, Key), Key accumulator) const;
	void removeHelper(Node*& node, const Key& element);
	std::pair<Key, Value> getMinElement(Node* node);
	std::ostream& serializeTreeHelper(Node* node, std::ostream& out);
	void eraseHelper(Node* node);
public:
	BinaryTree(std::pair<Key, Value>* array, int size);
	void prettyPrint() const;
	bool contains(const Key& element) const;
	size_t calculateHeight() const;
	Key sumLeaves() const;
	size_t countLeaves() const;
	void remove(const Key& element);
	Key reduce(Key(*operation)(Key, Key), Key accumulator) const;
	std::ostream& serializeTree(std::ostream& out);
	~BinaryTree();
};

