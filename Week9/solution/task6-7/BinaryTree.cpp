#include "BinaryTree.h"
#include <iomanip>
#include <iostream>

template <typename T>
typename BinaryTree<T>::Node* BinaryTree<T>::constructorHelper(T* array, int size)
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

template <typename T>
void BinaryTree<T>::printHelper(Node* node, int spaces) const
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
typename BinaryTree<T>::Node* BinaryTree<T>::parseExpressionHelper(std::string s)
{
	int i = 1;
	int scopes = 0;
	bool digitsOnly = true;

	for(char el : s)
	{
		if(el < '0' || el > '9')
		{
			digitsOnly = false;
		}
	}

	if (digitsOnly) return new Node{ s, nullptr, nullptr };

	if (s[i] == '(')
	{
		scopes++;
		i++;
		while (scopes != 0)
		{
			if (s[i] == '(') scopes++;
			if (s[i] == ')') scopes--;
			i++;
		}
	}
	else
	{
		while (s[i] >= '0' && s[i] <= '9')i++;
	}
	
	if(s[i] == ')')
	{
		return new Node{ s.substr(1, i - 1), nullptr, nullptr };
	}
	else
	{
		std::string operation(1, s[i]);
		std::string leftSubTree = s.substr(1, i - 1);
		std::string rightSubTree = s.substr(i + 1, s.size() - i - 2);
		
		return new Node{ operation, parseExpressionHelper(leftSubTree), parseExpressionHelper(rightSubTree) };
	}
}

template <typename T>
long BinaryTree<T>::calculateExpressionTreeHelper(Node* node) const
{
	if(node == nullptr)
	{
		return 0;
	}
	if(node->left == nullptr && node->right == nullptr)
	{
		int result = 0;
		for(int i = 0; i < node->data.size(); i++)
		{
			result = result * 10 + (node->data[i] - '0');
		}
		return result;
	}
	int leftResult = calculateExpressionTreeHelper(node->left);
	int rightResult = calculateExpressionTreeHelper(node->right);
	if(node->data == "*")
	{
		return leftResult * rightResult;
	}
	if(node->data == "+")
	{
		return leftResult + rightResult;
	}
}

template <typename T>
bool BinaryTree<T>::containsHelper(Node* node, const T& element) const
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
size_t BinaryTree<T>::calculateHeightHelper(Node* node) const
{
	if(node == nullptr)
	{
		return 0;
	}

	return 1 + std::max(calculateHeightHelper(node->left), calculateHeightHelper(node->right));
}

template <typename T>
T BinaryTree<T>::sumLeavesHelper(Node* node) const
{
	if(node == nullptr)
	{
		return T();
	}
	if(node->left == nullptr && node->right == nullptr)
	{
		return node->data;
	}
	return sumLeavesHelper(node->left) + sumLeavesHelper(node->right);
}

template <typename T>
size_t BinaryTree<T>::countLeavesHelper(Node* node) const
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

template <typename T>
T BinaryTree<T>::reduceHelper(Node* node, T(* operation)(T, T), T accumulator) const
{
	if(node != nullptr)
	{
		return operation(operation(reduceHelper(node->left, operation, accumulator), node->data), reduceHelper(node->right, operation, accumulator));
	}
	return accumulator;
}

template <typename T>
void BinaryTree<T>::removeHelper(Node*& node, const T& element)
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
T BinaryTree<T>::getMinElement(Node* node)
{
	while(node->left != nullptr)
	{
		node = node->left;
	}

	return node->data;
}

template <typename T>
std::ostream& BinaryTree<T>::serializeTreeHelper(Node* node, std::ostream& out)
{
	if(node == nullptr)
	{
		out << "()";
		return out;
	}
	out << "(" << node->data << " ";
	serializeTreeHelper(node->left, out);
	out << " ";
	serializeTreeHelper(node->right, out);
	out << ")";
	return out;
}

template <typename T>
void BinaryTree<T>::eraseHelper(Node* node)
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
BinaryTree<T>::BinaryTree() : root(nullptr)
{
}

template <typename T>
BinaryTree<T>::BinaryTree(T* array, int size)
{
	root = constructorHelper(array, size);
}

template <typename T>
void BinaryTree<T>::prettyPrint() const
{
	printHelper(root);
}

template <typename T>
void BinaryTree<T>::parseExpression(std::string s)
{
	eraseHelper(root);
	root = parseExpressionHelper(s);
}

template <typename T>
long BinaryTree<T>::calculateExpressionTree() const
{
	return calculateExpressionTreeHelper(root);
}

template <typename T>
bool BinaryTree<T>::contains(const T& element) const
{
	return containsHelper(root, element);
}

template <typename T>
size_t BinaryTree<T>::calculateHeight() const
{
	return calculateHeightHelper(root);
}

template <typename T>
T BinaryTree<T>::sumLeaves() const
{
	return sumLeavesHelper(root);
}

template <typename T>
size_t BinaryTree<T>::countLeaves() const
{
	return countLeavesHelper(root);
}

template <typename T>
void BinaryTree<T>::remove(const T& element)
{
	return removeHelper(root, element);
}

template <typename T>
T BinaryTree<T>::reduce(T(* operation)(T, T), T accumulator) const
{
	return reduceHelper(root, operation, accumulator);
}

template<typename T>
std::ostream& BinaryTree<T>::serializeTree(std::ostream& out)
{
	serializeTreeHelper(root, out);
	out << '\n';
	return out;
}

template<typename T>
BinaryTree<T>::~BinaryTree()
{
	eraseHelper(root);
}
