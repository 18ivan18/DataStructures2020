#include "AVLTree.h"
#include <iomanip>
#include <iostream>

template <typename T>
void AVLTree<T>::printHelper(Node* node, int spaces) const
{
	if (node != nullptr) {
		if (node->right) {
			printHelper(node->right, spaces + 4);
		}
		if (spaces) {
			std::cout << std::setw(spaces) << ' ';
		}
		if (node->right) std::cout << " /\n" << std::setw(spaces) << ' ';
		std::cout << node->data << "\n ";
		if (node->left) {
			std::cout << std::setw(spaces) << ' ' << " \\\n";
			printHelper(node->left, spaces + 4);
		}
	}
}

template <typename T>
bool AVLTree<T>::containsHelper(Node* node, const T& element) const
{
	if(node == nullptr)
	{
		return false;
	}
	if(node->data == element)
	{
		return true;
	}
	return containsHelper(node->left, element) || containsHelper(node->right, element);
}

template <typename T>
size_t AVLTree<T>::calculateHeightHelper(Node* node) const
{
	if(node == nullptr)
	{
		return 0;
	}

	return 1 + std::max(calculateHeightHelper(node->left), calculateHeightHelper(node->right));
}

template <typename T>
void AVLTree<T>::removeHelper(Node*& node, const T& element)
{
	if(node == nullptr)
	{
		return;
	}
	
	if(element < node->data)
	{
		return removeHelper(node->left, element);
	}

	if(element > node->data)
	{
		return removeHelper(node->right, element);
	}

	if(element == node->data)
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

		T minElement = getMinElement(node->right);
		node->data = minElement;

		removeHelper(node->right, minElement);
	}
}

template <typename T>
T AVLTree<T>::getMinElement(Node* node)
{
	while(node->left != nullptr)
	{
		node = node->left;
	}

	return node->data;
}

template <typename T>
void AVLTree<T>::eraseHelper(Node* node)
{
	if(node == nullptr)
	{
		return;
	}
	eraseHelper(node->left);
	eraseHelper(node->right);
	delete node;
}

template <typename T>
int AVLTree<T>::getSubtreeDifference(Node* node) const
{
	int leftHeight = calculateHeightHelper(node->left);
	int rightHeight = calculateHeightHelper(node->right);

	return leftHeight - rightHeight;
}

template <typename T>
typename AVLTree<T>::Node* AVLTree<T>::leftRotation(Node* node)
{
	Node* temp = node->right;
	node->right = nullptr;
	temp->left = node;

	return temp;
}

template <typename T>
typename AVLTree<T>::Node* AVLTree<T>::rightRotation(Node* node)
{
	Node* temp = node->left;
	node->left = nullptr;
	temp->right = node;

	return temp;
}

template <typename T>
typename AVLTree<T>::Node* AVLTree<T>::leftRightRotation(Node* node)
{
	Node* temp = node->left;
	node->left = leftRotation(temp);

	return rightRotation(node);
}

template <typename T>
typename AVLTree<T>::Node* AVLTree<T>::rightLeftRotation(Node* node)
{
	Node* temp = node->right;
	node->right = rightRotation(temp);

	return leftRotation(node);
}

template <typename T>
typename AVLTree<T>::Node*& AVLTree<T>::balance(Node*& node)
{
	int balanceFactor = getSubtreeDifference(node);
	if(balanceFactor > 1)
	{
		if(getSubtreeDifference(node->left) > 0)
		{
			node = rightRotation(node);
		}
		else
		{
			node = leftRightRotation(node);
		}
	} else if(balanceFactor < -1)
	{
		if(getSubtreeDifference(node->right) > 0)
		{
			node = rightLeftRotation(node);
		}
		else
		{
			node = leftRotation(node);
		}
	}
	return node;
}

template <typename T>
typename AVLTree<T>::Node* AVLTree<T>::insertHelper(Node*& node, const T& element)
{
	if(node == nullptr)
	{
		return new Node{ element, nullptr, nullptr };
	}
	else if(element < node->data)
	{
		node->left = insertHelper(node->left, element);
		node = balance(node);
	}
	else if(element >= node->data)
	{
		node->right = insertHelper(node->right, element);
		node = balance(node);
	}
	
	return node;
}

template <typename T>
AVLTree<T>::AVLTree() : root(nullptr)
{
}

template <typename T>
AVLTree<T>& AVLTree<T>::insert(T element)
{
	root = insertHelper(root, element);
	return *this;
}

template <typename T>
void AVLTree<T>::prettyPrint() const
{
	printHelper(root);
}

template <typename T>
bool AVLTree<T>::contains(const T& element) const
{
	return containsHelper(root, element);
}

template <typename T>
size_t AVLTree<T>::calculateHeight() const
{
	return calculateHeightHelper(root);
}

template <typename T>
void AVLTree<T>::remove(const T& element)
{
	return removeHelper(root, element);
}

template<typename T>
AVLTree<T>::~AVLTree()
{
	eraseHelper(root);
}
