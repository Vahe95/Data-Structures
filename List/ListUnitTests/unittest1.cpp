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
		std::string toString(List<int>& list)
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
			List<int> list;
		}

		TEST_METHOD(CCTOR)
		{
			List<int> list1;

			list1.pushBack(10);
			list1.pushBack(20);
			list1.pushBack(30);
			list1.pushBack(40);

			List<int> list2(list1);

			list1.popBack();

			const std::string expected = "10 20 30 40 ";
			const std::string actual = toString(list2);
			Assert::AreEqual(expected, actual, L"", LINE_INFO());
		}

		TEST_METHOD(operatorEqualTest)
		{
			List<int> list1;

			list1.pushBack(10);
			list1.pushBack(20);
			list1.pushBack(30);
			list1.pushBack(40);

			List<int> list2;

			list2 = list1;

			const std::string expected = "10 20 30 40 ";
			const std::string actual = toString(list2);
			Assert::AreEqual(expected, actual, L"", LINE_INFO());
		}

		TEST_METHOD(sizeTest01)
		{
			List<int> list;

			const int expected = 0;
			const int actual = list.size();
			Assert::AreEqual(expected, actual, L"", LINE_INFO());
		}

		TEST_METHOD(sizeTest02)
		{
			List<int> list;

			list.pushBack(10);
			list.pushBack(20);
			list.pushBack(30);
			list.pushBack(40);

			const int expected = 4;
			const int actual = list.size();
			Assert::AreEqual(expected, actual, L"", LINE_INFO());
		}

		TEST_METHOD(pushBackTest)
		{
			List<int> list;

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
			List<int> list;

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
			List<int> list;

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
			List<int> list;

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
			List<int> list;

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
			List<int> list;

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
			List<int> list;

			const bool expected = true;
			const bool actual = list.isEmpty();
			Assert::AreEqual(expected, actual, L"", LINE_INFO());
		}

		TEST_METHOD(isNotEmptyTest)
		{
			List<int> list;

			list.pushBack(10);

			const bool expected = false;
			const bool actual = list.isEmpty();
			Assert::AreEqual(expected, actual, L"", LINE_INFO());
		}

		TEST_METHOD(beginTest)
		{
			List<int> list;

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
			List<int> list;

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
			List<int> list;

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
			List<int> list;

			list.pushBack(10);
			list.pushBack(20);
			list.pushBack(30);
			list.pushBack(40);

			list.erase(++(++list.begin()));

			const std::string expected = "10 20 40 ";
			const std::string actual = toString(list);
			Assert::AreEqual(expected, actual, L"", LINE_INFO());
		}

		TEST_METHOD(underflowErrorTest01)
		{
			List<int> list;

			try
			{
				list.popBack();
			}
			catch (std::underflow_error& e)
			{
				const std::string expected("Stack is Empty!");
				const std::string actual(e.what());
				Assert::AreEqual(expected, actual, L"", LINE_INFO());
			}
		}

		TEST_METHOD(underflowErrorTest02)
		{
			List<int> list;

			try
			{
				list.popFront();
			}
			catch (std::underflow_error& e)
			{
				const std::string expected("Stack is Empty!");
				const std::string actual(e.what());
				Assert::AreEqual(expected, actual, L"", LINE_INFO());
			}
		}

		TEST_METHOD(underflowErrorTest03)
		{
			List<int> list;

			try
			{
				list.erase(list.begin());
			}
			catch (std::underflow_error& e)
			{
				const std::string expected("Stack is Empty!");
				const std::string actual(e.what());
				Assert::AreEqual(expected, actual, L"", LINE_INFO());
			}
		}
	};
}