#include <iostream>
#include "BinaryTree.cpp"

int main()
{
	int arr[] = { 1, 8, 11, 23, 42, 55, 67, 72, 77, 81, 86, 90, 93 };
	
	BinaryTree<std::string> tree;
	tree.parseExpression("(((1*1)+50)*(82+32))");
	tree.prettyPrint();
	std::cout << "Result:" << tree.calculateExpressionTree() << "\n";
	return 0;
}
