#include "stdafx.h"
#include "CppUnitTest.h"
#include "List.h"
#include <string>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace ListUnitTests
{
	TEST_CLASS(ListTests)
	{
	private:
		std::string toString(DataStructure::List<int>& list)
		{
			std::string result = "";

			for (auto it = list.begin(); it != list.end(); ++it)
			{
				result += std::to_string(*it);
				result += " ";
			}

			return result;
		}

	public:
		TEST_METHOD(CTOR)
		{
			DataStructure::List<int> list;
		}

		TEST_METHOD(CCTOR)
		{
			DataStructure::List<int> list1;

			list1.pushBack(10);
			list1.pushBack(20);
			list1.pushBack(30);
			list1.pushBack(40);

			DataStructure::List<int> list2(list1);

			list1.popBack();

			const std::string expected = "10 20 30 40 ";
			const std::string actual = toString(list2);
			Assert::AreEqual(expected, actual, L"", LINE_INFO());
		}

		TEST_METHOD(operatorAssignmentTest)
		{
			DataStructure::List<int> list1;

			list1.pushBack(10);
			list1.pushBack(20);
			list1.pushBack(30);
			list1.pushBack(40);

			DataStructure::List<int> list2;

			list2 = list1;

			const std::string expected = "10 20 30 40 ";
			const std::string actual = toString(list2);
			Assert::AreEqual(expected, actual, L"", LINE_INFO());
		}

		TEST_METHOD(sizeTest01)
		{
			DataStructure::List<int> list;

			const size_t expected = 0;
			const size_t actual = list.size();
			Assert::AreEqual(expected, actual, L"", LINE_INFO());
		}

		TEST_METHOD(sizeTest02)
		{
			DataStructure::List<int> list;

			list.pushBack(10);
			list.pushBack(20);
			list.pushBack(30);
			list.pushBack(40);

			const size_t expected = 4;
			const size_t actual = list.size();
			Assert::AreEqual(expected, actual, L"", LINE_INFO());
		}

		TEST_METHOD(pushBackTest)
		{
			DataStructure::List<int> list;

			list.pushBack(10);
			list.pushBack(20);
			list.pushBack(30);
			list.pushBack(40);

			const std::string expected = "10 20 30 40 ";
			const std::string actual = toString(list);
			Assert::AreEqual(expected, actual, L"", LINE_INFO());
		}

		TEST_METHOD(popBackTest)
		{
			DataStructure::List<int> list;

			list.pushBack(10);
			list.pushBack(20);
			list.pushBack(30);
			list.pushBack(40);

			list.popBack();

			const std::string expected = "10 20 30 ";
			const std::string actual = toString(list);
			Assert::AreEqual(expected, actual, L"", LINE_INFO());
		}

		TEST_METHOD(pushFrontTest)
		{
			DataStructure::List<int> list;

			list.pushFront(10);
			list.pushFront(20);
			list.pushFront(30);
			list.pushFront(40);

			const std::string expected = "40 30 20 10 ";
			const std::string actual = toString(list);
			Assert::AreEqual(expected, actual, L"", LINE_INFO());
		}

		TEST_METHOD(popFrontTest)
		{
			DataStructure::List<int> list;

			list.pushFront(10);
			list.pushFront(20);
			list.pushFront(30);
			list.pushFront(40);

			list.popFront();

			const std::string expected = "30 20 10 ";
			const std::string actual = toString(list);
			Assert::AreEqual(expected, actual, L"", LINE_INFO());
		}

		TEST_METHOD(frontTest)
		{
			DataStructure::List<int> list;

			list.pushBack(10);
			list.pushBack(20);
			list.pushBack(30);
			list.pushBack(40);

			const int expected = 10;
			const int actual = list.front();
			Assert::AreEqual(expected, actual, L"", LINE_INFO());
		}

		TEST_METHOD(backTest)
		{
			DataStructure::List<int> list;

			list.pushBack(10);
			list.pushBack(20);
			list.pushBack(30);
			list.pushBack(40);

			const int expected = 40;
			const int actual = list.back();
			Assert::AreEqual(expected, actual, L"", LINE_INFO());
		}

		TEST_METHOD(isEmptyTest)
		{
			DataStructure::List<int> list;

			const bool expected = true;
			const bool actual = list.empty();
			Assert::AreEqual(expected, actual, L"", LINE_INFO());
		}

		TEST_METHOD(isNotEmptyTest)
		{
			DataStructure::List<int> list;

			list.pushBack(10);

			const bool expected = false;
			const bool actual = list.empty();
			Assert::AreEqual(expected, actual, L"", LINE_INFO());
		}

		TEST_METHOD(beginTest)
		{
			DataStructure::List<int> list;

			list.pushBack(10);
			list.pushBack(20);
			list.pushBack(30);
			list.pushBack(40);

			const int expected = 10;
			const int actual = *list.begin();
			Assert::AreEqual(expected, actual, L"", LINE_INFO());
		}

		TEST_METHOD(endTest)
		{
			DataStructure::List<int> list;

			list.pushBack(10);
			list.pushBack(20);
			list.pushBack(30);
			list.pushBack(40);

			const int expected = 40;
			const int actual = *(--list.end());
			Assert::AreEqual(expected, actual, L"", LINE_INFO());
		}

		TEST_METHOD(insertTest)
		{
			DataStructure::List<int> list;

			list.pushBack(10);
			list.pushBack(20);
			list.pushBack(30);
			list.pushBack(40);

			list.insert(++(++list.begin()), 50);

			const std::string expected = "10 20 50 30 40 ";
			const std::string actual = toString(list);
			Assert::AreEqual(expected, actual, L"", LINE_INFO());
		}

		TEST_METHOD(eraseTest)
		{
			DataStructure::List<int> list;

			list.pushBack(10);
			list.pushBack(20);
			list.pushBack(30);
			list.pushBack(40);

			list.erase(++(++list.cbegin()));

			const std::string expected = "10 20 40 ";
			const std::string actual = toString(list);
			Assert::AreEqual(expected, actual, L"", LINE_INFO());
		}

		TEST_METHOD(preIncrementTest)
		{
			DataStructure::List<int> list;

			list.pushBack(10);
			list.pushBack(20);

			const int expected = 20;
			const int actual = *(++list.begin());
			Assert::AreEqual(expected, actual, L"", LINE_INFO());
		}

		TEST_METHOD(postIncrementTest)
		{
			DataStructure::List<int> list;

			list.pushBack(10);
			list.pushBack(20);

			const int expected = 10;
			const int actual = *(list.begin()++);
			Assert::AreEqual(expected, actual, L"", LINE_INFO());
		}

		TEST_METHOD(preDecrementTest)
		{
			DataStructure::List<int> list;

			list.pushBack(10);
			list.pushBack(20);

			const int expected = 20;
			const int actual = *(--list.end());
			Assert::AreEqual(expected, actual, L"", LINE_INFO());
		}

		TEST_METHOD(postDecrementTest)
		{
			DataStructure::List<int> list;

			list.pushBack(10);
			list.pushBack(20);

			const int expected = 10;
			const int actual = *(list.end()--);
			Assert::AreEqual(expected, actual, L"", LINE_INFO());
		}

		TEST_METHOD(underflowErrorTest01)
		{
			DataStructure::List<int> list;

			try
			{
				list.popBack();
			}
			catch (std::underflow_error& e)
			{
				const std::string expected("List is Empty!");
				const std::string actual(e.what());
				Assert::AreEqual(expected, actual, L"", LINE_INFO());
			}
		}

		TEST_METHOD(underflowErrorTest02)
		{
			DataStructure::List<int> list;

			try
			{
				list.popFront();
			}
			catch (std::underflow_error& e)
			{
				const std::string expected("List is Empty!");
				const std::string actual(e.what());
				Assert::AreEqual(expected, actual, L"", LINE_INFO());
			}
		}

		TEST_METHOD(underflowErrorTest03)
		{
			DataStructure::List<int> list;

			try
			{
				list.erase(list.cbegin());
			}
			catch (std::underflow_error& e)
			{
				const std::string expected("List is Empty!");
				const std::string actual(e.what());
				Assert::AreEqual(expected, actual, L"", LINE_INFO());
			}
		}
	};
}