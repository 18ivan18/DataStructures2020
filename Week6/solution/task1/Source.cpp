#include <iostream>
#include <fstream>
#include "BinaryTree.cpp"

int main()
{
	std::pair<int, std::string> arr[13];
	arr[0] = { 1, "Plovdiv" };
	arr[1] = { 8, "StaraZagora" };
	arr[2] = { 11, "Pleven" };
	arr[3] = { 23, "Silistra" };
	arr[4] = { 42, "Burgas" };
	arr[5] = { 55, "Varna" };
	arr[6] = { 67, "Yambol" };
	arr[7] = { 72, "Pazardjik" };
	arr[8] = { 77, "Sofia" };
	arr[9] = { 81, "Pernik" };
	arr[10] = { 86, "Ruse" };
	arr[11] = { 90, "Shumen" };
	arr[12] = { 93, "Kazanluk" };
	
	BinaryTree<int, std::string> tree(arr, sizeof(arr) / sizeof(std::pair<int, std::string>));
	tree.prettyPrint();
	std::cout << "Height:" << tree.calculateHeight() << '\n';
	std::cout << "Num leaves:" << tree.countLeaves() << '\n';
	std::cout << "Sum leaves:" << tree.sumLeaves() << '\n';
	std::cout << "Product mod 44777:" << tree.reduce([](int a, int b) {return (a * b) % 44777; }, 1) << '\n';
	std::cout << "Contains 23?:" << (tree.contains(23) ? "Yes\n" : "No\n");
	tree.remove(23);
	std::cout << "Contains 23?:" << (tree.contains(23) ? "Yes\n" : "No\n");
	tree.prettyPrint();

	std::ofstream file("save.tree");
	tree.serializeTree(file);
	file.close();
	
	return 0;
}
