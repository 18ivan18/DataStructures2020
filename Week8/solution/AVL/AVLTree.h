#pragma once
#include <ostream>

template<typename T>
class AVLTree
{
private:
	struct Node
	{
		T data;
		Node* left;
		Node* right;
	};
	Node* root;
	
	void printHelper(Node* node, int spaces = 0) const;
	bool containsHelper(Node* node, const T& element) const;
	size_t calculateHeightHelper(Node* node) const;
	void removeHelper(Node*& node, const T& element);
	T getMinElement(Node* node);
	void eraseHelper(Node* node);
	int getSubtreeDifference(Node* node) const;
	Node* leftRotation(Node* node);
	Node* rightRotation(Node* node);
	Node* leftRightRotation(Node* node);
	Node* rightLeftRotation(Node* node);
	Node*& balance(Node*& node);
	Node* insertHelper(Node*& node, const T& element);
public:
	AVLTree();
	AVLTree& insert(T element);
	void prettyPrint() const;
	bool contains(const T& element) const;
	size_t calculateHeight() const;
	void remove(const T& element);
	~AVLTree();
};

