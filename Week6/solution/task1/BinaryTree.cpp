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
bool BinaryTree<Key, Value>::containsHelper(Node* node, const Key& element) const
{
	if(node == nullptr)
	{
		return false;
	}
	if(node->data.first == element)
	{
		return true;
	}
	return containsHelper(node->left, element) || containsHelper(node->right, element);
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

template<typename Key, typename Value>
Key BinaryTree<Key, Value>::sumLeavesHelper(Node* node) const
{
	if(node == nullptr)
	{
		return Key();
	}
	if(node->left == nullptr && node->right == nullptr)
	{
		return node->data.first;
	}
	return sumLeavesHelper(node->left) + sumLeavesHelper(node->right);
}

template<typename Key, typename Value>
size_t BinaryTree<Key, Value>::countLeavesHelper(Node* node) const
{
	if (node == nullptr)
	{
		return 0;
	}
	if (node->left == nullptr && node->right == nullptr)
	{
		return 1;
	}
	return countLeavesHelper(node->left) + countLeavesHelper(node->right);
}

template<typename Key, typename Value>
Key BinaryTree<Key, Value>::reduceHelper(Node* node, Key(* operation)(Key, Key), Key accumulator) const
{
	if(node != nullptr)
	{
		return operation(operation(reduceHelper(node->left, operation, accumulator), node->data.first), reduceHelper(node->right, operation, accumulator));
	}
	return accumulator;
}

template<typename Key, typename Value>
void BinaryTree<Key, Value>::removeHelper(Node*& node, const Key& element)
{
	if(node == nullptr)
	{
		return;
	}
	
	if(element < node->data.first)
	{
		return removeHelper(node->left, element);
	}

	if(element > node->data.first)
	{
		return removeHelper(node->right, element);
	}

	if(element == node->data.first)
	{
		if(node->left == nullptr && node->right == nullptr)
		{
			Node* save = node;
			node = nullptr;
			delete save;
			return;
		}

		if(node->left == nullptr)
		{
			Node* save = node;
			node = node->left;
			delete save;
			return;
		}

		if(node->right == nullptr)
		{
			Node* save = node;
			node = node->right;
			delete save;
			return;
		}

		std::pair<Key, Value> minElement = getMinElement(node->right);
		node->data = minElement;

		removeHelper(node->right, minElement.first);
	}
}

template<typename Key, typename Value>
std::pair<Key, Value> BinaryTree<Key, Value>::getMinElement(Node* node)
{
	while(node->left != nullptr)
	{
		node = node->left;
	}

	return node->data;
}

template<typename Key, typename Value>
std::ostream& BinaryTree<Key, Value>::serializeTreeHelper(Node* node, std::ostream& out)
{
	if(node == nullptr)
	{
		out << "()";
		return out;
	}
	out << "(" << node->data.first << ":" << node->data.second << " ";
	serializeTreeHelper(node->left, out);
	out << " ";
	serializeTreeHelper(node->right, out);
	out << ")";
	return out;
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
void BinaryTree<Key, Value>::prettyPrint() const
{
	printHelper(root);
}

template<typename Key, typename Value>
bool BinaryTree<Key, Value>::contains(const Key& element) const
{
	return containsHelper(root, element);
}

template<typename Key, typename Value>
size_t BinaryTree<Key, Value>::calculateHeight() const
{
	return calculateHeightHelper(root);
}

template<typename Key, typename Value>
Key BinaryTree<Key, Value>::sumLeaves() const
{
	return sumLeavesHelper(root);
}

template<typename Key, typename Value>
size_t BinaryTree<Key, Value>::countLeaves() const
{
	return countLeavesHelper(root);
}

template<typename Key, typename Value>
void BinaryTree<Key, Value>::remove(const Key& element)
{
	return removeHelper(root, element);
}

template<typename Key, typename Value>
Key BinaryTree<Key, Value>::reduce(Key(* operation)(Key, Key), Key accumulator) const
{
	return reduceHelper(root, operation, accumulator);
}

template<typename Key, typename Value>
std::ostream& BinaryTree<Key, Value>::serializeTree(std::ostream& out)
{
	serializeTreeHelper(root, out);
	out << '\n';
	return out;
}

template<typename Key, typename Value>
BinaryTree<Key, Value>::~BinaryTree()
{
	eraseHelper(root);
}
