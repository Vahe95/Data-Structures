#include "stdafx.h"
#include "CppUnitTest.h"
#include "BinarySearchTree.h"
#include <iostream>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace BinarySearchTreeUnitTests
{		
	TEST_CLASS(BinarySearchTreeTest)
	{
	public:
		
		TEST_METHOD(CTOR)
		{
			BinarySearchTree<int> tree;
		}

		TEST_METHOD(CTOR_initializer_list)
		{
			BinarySearchTree<int> tree{ 10, 20, 30, 40 };
		}

		TEST_METHOD(minTest)
		{
			BinarySearchTree<int> tree{ 50, 12, 9, 23, 125, 1, 256, 138, 44, 100 };

			const int expected = 1;
			const int actual = tree.min()->m_data;
			Assert::AreEqual(expected, actual, L"", LINE_INFO());
		}

		TEST_METHOD(maxTest)
		{
			BinarySearchTree<int> tree{ 50, 12, 9, 23, 125, 1, 256, 138, 44, 100 };

			const int expected = 256;
			const int actual = tree.max()->m_data;
			Assert::AreEqual(expected, actual, L"", LINE_INFO());
		}

		TEST_METHOD(inorder_print_Test)
		{
			BinarySearchTree<int> tree{ 15, 5, 7, 25, 14, 3, 55 };

			std::ostringstream os;

			auto coutBuf = std::cout.rdbuf();
			auto osBuf = os.rdbuf();
			std::cout.rdbuf(osBuf);
			
			tree.print_inorder();

			std::cout.rdbuf(coutBuf);

			const std::string actual = os.str();
			const std::string expected = "3 5 7 14 15 25 55 ";
			Assert::AreEqual(expected, actual, L"", LINE_INFO());
		}

		TEST_METHOD(postorder_print_Test)
		{
			BinarySearchTree<int> tree{ 50, 12, 9, 23, 125, 1, 256, 138, 44, 100 };

			std::ostringstream os;

			auto coutBuf = std::cout.rdbuf();
			auto osBuf = os.rdbuf();
			std::cout.rdbuf(osBuf);

			tree.print_postorder();

			std::cout.rdbuf(coutBuf);

			const std::string actual = os.str();
			const std::string expected = "1 9 44 23 12 100 138 256 125 50 ";
			Assert::AreEqual(expected, actual, L"", LINE_INFO());
		}

		TEST_METHOD(preorder_print_Test)
		{
			BinarySearchTree<int> tree{ 50, 12, 9, 23, 125, 1, 256, 138, 44, 100 };

			std::ostringstream os;

			auto coutBuf = std::cout.rdbuf();
			auto osBuf = os.rdbuf();
			std::cout.rdbuf(osBuf);

			tree.print_preorder();

			std::cout.rdbuf(coutBuf);

			const std::string actual = os.str();
			const std::string expected = "50 12 9 1 23 44 125 100 256 138 ";
			Assert::AreEqual(expected, actual, L"", LINE_INFO());
		}

		TEST_METHOD(dfsTraversTest)
		{
			BinarySearchTree<int> tree{ 50, 12, 9, 23, 125, 1, 256, 138, 44, 100 };

			std::ostringstream os;

			auto coutBuf = std::cout.rdbuf();
			auto osBuf = os.rdbuf();
			std::cout.rdbuf(osBuf);

			tree.dfsTravers();

			std::cout.rdbuf(coutBuf);

			const std::string actual = os.str();
			const std::string expected = "50 125 256 138 100 12 23 44 9 1 ";
			Assert::AreEqual(expected, actual, L"", LINE_INFO());
		}

		TEST_METHOD(bfsTraversTest)
		{
			BinarySearchTree<int> tree{ 50, 12, 9, 23, 125, 1, 256, 138, 44, 100 };

			std::ostringstream os;

			auto coutBuf = std::cout.rdbuf();
			auto osBuf = os.rdbuf();
			std::cout.rdbuf(osBuf);

			tree.bfsTravers();

			std::cout.rdbuf(coutBuf);

			const std::string actual = os.str();
			const std::string expected = "50 12 125 9 23 100 256 1 44 138 ";
			Assert::AreEqual(expected, actual, L"", LINE_INFO());
		}

		TEST_METHOD(insertTest)
		{
			BinarySearchTree<int> tree{ 15, 5, 7, 25, 14, 3, 55 };

			std::ostringstream os;

			auto coutBuf = std::cout.rdbuf();
			auto osBuf = os.rdbuf();
			std::cout.rdbuf(osBuf);

			tree.insert(16);

			tree.print_inorder();

			std::cout.rdbuf(coutBuf);

			const std::string actual = os.str();
			const std::string expected = "3 5 7 14 15 16 25 55 ";
			Assert::AreEqual(expected, actual, L"", LINE_INFO());
		}
		
		TEST_METHOD(minDepthTest)
		{
			BinarySearchTree<int> tree{ 50, 12, 9, 23, 125, 1, 256, 138, 44, 100 };

			const int expected = 2;
			const int actual = tree.minDepth();
			Assert::AreEqual(expected, actual, L"", LINE_INFO());
		}

		TEST_METHOD(maxDepthTest)
		{
			BinarySearchTree<int> tree{ 50, 12, 9, 23, 125, 1, 256, 138, 44, 100 };

			const int expected = 3;
			const int actual = tree.maxDepth();
			Assert::AreEqual(expected, actual, L"", LINE_INFO());
		}

		TEST_METHOD(lcaTest01)
		{
			BinarySearchTree<int> tree{ 50, 12, 9, 23, 125, 1, 256, 138, 44, 100 };

			const int expected = 125;
			const int actual = tree.lca(100, 138)->m_data;
			Assert::AreEqual(expected, actual, L"", LINE_INFO());
		}

		TEST_METHOD(lcaTest02)
		{
			BinarySearchTree<int> tree{ 50, 12, 9, 23, 125, 1, 256, 138, 44, 100 };

			const int expected = 12;
			const int actual = tree.lca(9, 44)->m_data;
			Assert::AreEqual(expected, actual, L"", LINE_INFO());
		}

		TEST_METHOD(lcaTest03)
		{
			BinarySearchTree<int> tree{ 50, 12, 9, 23, 125, 1, 256, 138, 44, 100 };

			const int expected = 50;
			const int actual = tree.lca(44, 256)->m_data;
			Assert::AreEqual(expected, actual, L"", LINE_INFO());
		}

		TEST_METHOD(findNodeTest)
		{
			BinarySearchTree<int> tree{ 50, 12, 9, 23, 125, 1, 256, 138, 44, 100 };

			const int expected = 23;
			const int actual = tree.findNode(23)->m_data;
			Assert::AreEqual(expected, actual, L"", LINE_INFO());
		}

		TEST_METHOD(deleteNodeTest)
		{
			BinarySearchTree<int> tree{ 15, 5, 7, 25, 14, 3, 55 };
			
			tree.deleteNode(25);
			
			std::ostringstream os;

			auto coutBuf = std::cout.rdbuf();
			auto osBuf = os.rdbuf();
			std::cout.rdbuf(osBuf);
			
			tree.print_inorder();

			std::cout.rdbuf(coutBuf);

			const std::string actual = os.str();
			const std::string expected = "3 5 7 14 15 55 ";
			Assert::AreEqual(expected, actual, L"", LINE_INFO());			
		}

		TEST_METHOD(successorTest)
		{
			BinarySearchTree<int> tree{ 50, 12, 9, 23, 125, 1, 256, 138, 44, 100 };

			const int expected = 125;
			const int actual = tree.successor(tree.findNode(100))->m_data;
			Assert::AreEqual(expected, actual, L"", LINE_INFO());
		}

		TEST_METHOD(predecessorTest)
		{
			BinarySearchTree<int> tree{ 50, 12, 9, 23, 125, 1, 256, 138, 44, 100 };

			const int expected = 125;
			const int actual = tree.predecessor(tree.findNode(138))->m_data;
			Assert::AreEqual(expected, actual, L"", LINE_INFO());
		}

		TEST_METHOD(underflowErrorTest)
		{
			BinarySearchTree<int> tree;

			try
			{
				tree.deleteNode(10);
			}
			catch (const std::underflow_error& e)
			{
				const std::string expected = "Tree is Cut!";
				const std::string actual(e.what());
				Assert::AreEqual(expected, actual, L"", LINE_INFO());
			}
		}

		TEST_METHOD(treeIsNotPlantedTestForInorder)
		{
			BinarySearchTree<int> tree;

			try
			{
				tree.print_inorder();
			}
			catch (const std::runtime_error& e)
			{
				const std::string expected = "The Tree is Not Planted!";
				const std::string actual(e.what());
				Assert::AreEqual(expected, actual, L"", LINE_INFO());
			}
		}

		TEST_METHOD(treeIsNotPlantedTestForPreorder)
		{
			BinarySearchTree<int> tree;

			try
			{
				tree.print_preorder();
			}
			catch (const std::runtime_error& e)
			{
				const std::string expected = "The Tree is Not Planted!";
				const std::string actual(e.what());
				Assert::AreEqual(expected, actual, L"", LINE_INFO());
			}
		}

		TEST_METHOD(treeIsNotPlantedTestForPostorder)
		{
			BinarySearchTree<int> tree;

			try
			{
				tree.print_postorder();
			}
			catch (const std::runtime_error& e)
			{
				const std::string expected = "The Tree is Not Planted!";
				const std::string actual(e.what());
				Assert::AreEqual(expected, actual, L"", LINE_INFO());
			}
		}

		TEST_METHOD(treeIsNotPlantedMinTest)
		{
			BinarySearchTree<int> tree;

			try
			{
				tree.min();
			}
			catch (const std::runtime_error& e)
			{
				const std::string expected = "The Tree is Not Planted!";
				const std::string actual(e.what());
				Assert::AreEqual(expected, actual, L"", LINE_INFO());
			}
		}

		TEST_METHOD(treeIsNotPlantedMaxTest)
		{
			BinarySearchTree<int> tree;

			try
			{
				tree.max();
			}
			catch (const std::runtime_error& e)
			{
				const std::string expected = "The Tree is Not Planted!";
				const std::string actual(e.what());
				Assert::AreEqual(expected, actual, L"", LINE_INFO());
			}
		}

		TEST_METHOD(treeIsNotPlantedSuccessorTest)
		{
			BinarySearchTree<int> tree;

			try
			{
				tree.successor(tree.findNode(10));
			}
			catch (const std::runtime_error& e)
			{
				const std::string expected = "The Tree is Not Planted!";
				const std::string actual(e.what());
				Assert::AreEqual(expected, actual, L"", LINE_INFO());
			}
		}

		TEST_METHOD(treeIsNotPlantedPredecessorTest)
		{
			BinarySearchTree<int> tree;

			try
			{
				tree.predecessor(tree.findNode(10));
			}
			catch (const std::runtime_error& e)
			{
				const std::string expected = "The Tree is Not Planted!";
				const std::string actual(e.what());
				Assert::AreEqual(expected, actual, L"", LINE_INFO());
			}
		}

		TEST_METHOD(treeIsNotPlantedLCATest)
		{
			BinarySearchTree<int> tree;

			try
			{
				tree.lca(10, 20);
			}
			catch (const std::runtime_error& e)
			{
				const std::string expected = "The Tree is Not Planted!";
				const std::string actual(e.what());
				Assert::AreEqual(expected, actual, L"", LINE_INFO());
			}
		}
	};
}