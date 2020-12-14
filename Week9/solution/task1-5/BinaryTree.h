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
	Node* balanceConstructor(const int& startH, const int& h);
	void printHelper(Node* node, int spaces = 0) const;
	bool isOrderedHelper(Node* node) const;
	bool isBalancedHelper(Node* node) const;
	size_t calculateHeightHelper(Node* node) const;
	void mirrorTreeHelper(Node*& node);
	int childrenifyHelper(Node* node);
	void eraseHelper(Node* node);
public:
	BinaryTree(std::pair<Key, Value>* array, int size);
	BinaryTree(const int& h);
	void prettyPrint() const;
	bool isOrdered() const;
	bool isBalanced() const;
	size_t calculateHeight() const;
	void mirrorTree();
	void childrenify();
	~BinaryTree();
};

