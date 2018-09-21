#include <iostream>
#include "BinarySearchTree.h"

int main()
{
	BinarySearchTree<int> tree{ 50, 12, 9, 23, 125, 1, 256, 138, 44, 100 };
	
	std::cout << tree.successor(tree.findNode(256))->m_data << std::endl;

	tree.print_preorder();

	return 0;
}