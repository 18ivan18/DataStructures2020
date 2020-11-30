#include "AVLTree.cpp"

int main()
{
	AVLTree<int> tree;
	tree.insert(1)
		.insert(-2)
		.insert(-4)
		.insert(4)
		.insert(5)
		.insert(13)
		.insert(-2)
		.insert(-5)
		.insert(-5)
		.insert(11)
		.insert(10);
	/*
	 * insert
	 * remove
	 * search
	 * treeHeight
	 * O(logN)
	 * log(1 000 000 000 000)
	 * 
	 */

	tree.prettyPrint();
	return 0;
}
