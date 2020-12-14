#pragma once
#include <ostream>

template<typename T>
class BinaryTree
{
private:
	struct Node
	{
		T data;
		Node* left;
		Node* right;
	};
	Node* root;
	
	Node* constructorHelper(T* array, int size);
	void printHelper(Node* node, int spaces = 0) const;
	Node* parseExpressionHelper(std::string s);
	long calculateExpressionTreeHelper(Node* node) const;
	bool containsHelper(Node* node, const T& element) const;
	size_t calculateHeightHelper(Node* node) const;
	T sumLeavesHelper(Node* node) const;
	size_t countLeavesHelper(Node* node) const;
	T reduceHelper(Node* node, T(*operation)(T, T), T accumulator) const;
	void removeHelper(Node*& node, const T& element);
	T getMinElement(Node* node);
	std::ostream& serializeTreeHelper(Node* node, std::ostream& out);
	void eraseHelper(Node* node);
public:
	BinaryTree();
	BinaryTree(T* array, int size);
	void prettyPrint() const;
	void parseExpression(std::string s);
	long calculateExpressionTree() const;
	bool contains(const T& element) const;
	size_t calculateHeight() const;
	T sumLeaves() const;
	size_t countLeaves() const;
	void remove(const T& element);
	T reduce(T(*operation)(T, T), T accumulator) const;
	std::ostream& serializeTree(std::ostream& out);
	~BinaryTree();
};

