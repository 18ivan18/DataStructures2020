#include "BinaryTree.h"
#include <iomanip>
#include <iostream>

template<typename Key, typename Value>
typename BinaryTree<Key, Value>::Node* BinaryTree<Key, Value>::constructorHelper(std::pair<Key, Value>* array, int size)
{
	if (size == 0)
	{
		return nullptr;
	}
	else
	{
		int mid = size / 2;
		Node* node = new Node({array[mid], nullptr, nullptr});

		node->left = constructorHelper(array, mid);
		node->right = constructorHelper(array + mid + 1, size - mid - 1);

		return node;
	}
}

template<typename Key, typename Value>
typename BinaryTree<Key, Value>::Node* BinaryTree<Key, Value>::balanceConstructor(const int& startH, const int& h)
{
	if(h == startH)
	{
		return new Node({ {h, "balance" }, nullptr, nullptr });
	}
	else
	{
		return new Node({ { startH, "balance" }, balanceConstructor(startH + 1, h), balanceConstructor(startH + 1, h) });
	}
}

template<typename Key, typename Value>
void BinaryTree<Key, Value>::printHelper(Node* node, int spaces) const
{
	if (node != nullptr) {
		if (node->right) {
			printHelper(node->right, spaces + 4);
		}
		if (spaces) {
			std::cout << std::setw(spaces) << ' ';
		}
		if (node->right) std::cout << " /\n" << std::setw(spaces) << ' ';
		std::cout << node->data.first << ":" << node->data.second << "\n ";
		if (node->left) {
			std::cout << std::setw(spaces) << ' ' << " \\\n";
			printHelper(node->left, spaces + 4);
		}
	}
}

template<typename Key, typename Value>
bool BinaryTree<Key, Value>::isOrderedHelper(Node* node) const
{
	if(node == nullptr)
	{
		return true;
	}
	else if(node->left == nullptr && node->right == nullptr)
	{
		return true;
	}
	else if(node->left == nullptr && node->data.first > node->right->data.first)
	{
		return false;
	}
	else if (node->left == nullptr && node->data.first < node->right->data.first)
	{
		return isOrderedHelper(node->right);
	}
	else if(node->right == nullptr && node->data.first < node->left->data.first)
	{
		return false;
	}
	else if (node->right == nullptr && node->data.first > node->left->data.first)
	{
		return isOrderedHelper(node->left);
	}
	else
	{
		if(node->left->data.first <= node->data.first && node->data.first <= node->right->data.first)
		{
			return isOrderedHelper(node->left) && isOrderedHelper(node->right);
		}
		else
		{
			return false;
		}
	}
}

template <typename Key, typename Value>
bool BinaryTree<Key, Value>::isBalancedHelper(Node* node) const
{
	if(node == nullptr)
	{
		return true;
	}

	int leftTreeHeight = calculateHeightHelper(node->left);
	int rightTreeHeight = calculateHeightHelper(node->right);

	return (abs(leftTreeHeight - rightTreeHeight) <= 1 && isBalancedHelper(node->left) && isBalancedHelper(node->right));
}

template<typename Key, typename Value>
size_t BinaryTree<Key, Value>::calculateHeightHelper(Node* node) const
{
	if(node == nullptr)
	{
		return 0;
	}

	return 1 + std::max(calculateHeightHelper(node->left), calculateHeightHelper(node->right));
}

template <typename Key, typename Value>
void BinaryTree<Key, Value>::mirrorTreeHelper(Node*& node)
{
	if(node == nullptr)
	{
		return;
	}
	Node* temp;
	
	mirrorTreeHelper(node->left);
	mirrorTreeHelper(node->right);

	temp = node->left;
	node->left = node->right;
	node->right = temp;
}

template <typename Key, typename Value>
int BinaryTree<Key, Value>::childrenifyHelper(Node* node)
{
	if(node == nullptr)
	{
		return 0;
	}
	if (node->left == nullptr && node->right == nullptr)
	{
		node->data.first = 1;
		return 1;
	}
	node->data.first = childrenifyHelper(node->right) + childrenifyHelper(node->left) + 1;
	return node->data.first;
}


template<typename Key, typename Value>
void BinaryTree<Key, Value>::eraseHelper(Node* node)
{
	if(node == nullptr)
	{
		return;
	}
	eraseHelper(node->left);
	eraseHelper(node->right);
	delete node;
}

template<typename Key, typename Value>
BinaryTree<Key, Value>::BinaryTree(std::pair<Key, Value>* array, int size)
{
	root = constructorHelper(array, size);
}

template<typename Key, typename Value>
BinaryTree<Key, Value>::BinaryTree(const int& h)
{
	if (h >= 0)
		root = balanceConstructor(0, h);
	else
		root = nullptr;
}

template<typename Key, typename Value>
void BinaryTree<Key, Value>::prettyPrint() const
{
	printHelper(root);
}

template<typename Key, typename Value>
bool BinaryTree<Key, Value>::isOrdered() const
{
	return isOrderedHelper(root);
}

template <typename Key, typename Value>
bool BinaryTree<Key, Value>::isBalanced() const
{
	return isBalancedHelper(root);
}

template<typename Key, typename Value>
size_t BinaryTree<Key, Value>::calculateHeight() const
{
	return calculateHeightHelper(root);
}

template <typename Key, typename Value>
void BinaryTree<Key, Value>::mirrorTree()
{
	mirrorTreeHelper(root);
}

template <typename Key, typename Value>
void BinaryTree<Key, Value>::childrenify()
{
	childrenifyHelper(root);
}

template<typename Key, typename Value>
BinaryTree<Key, Value>::~BinaryTree()
{
	eraseHelper(root);
}
