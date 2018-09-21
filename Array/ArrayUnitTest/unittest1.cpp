#include "stdafx.h"
//#include "CppUnitTest.h"
//#include "../../Array/Array/Array.h"
//
//using namespace Microsoft::VisualStudio::CppUnitTestFramework;
//
//namespace ArrayUnitTest
//{		
//	TEST_CLASS(ArrayUnitTest)
//	{
//	private:
//		static std::string toString(Array<int>& array)
//		{
//			std::string result;
//
//			for (int i = 0; i < array.size(); i++)
//			{
//				const int value = array[i];
//
//				result += std::to_string(value);
//				result += ' ';
//			}
//
//			return result;
//		}
//
//	public:
//
//		TEST_METHOD(CTOR)
//		{
//			Array<int> array;
//		}
//		
//		TEST_METHOD(sizeTest01)
//		{
//			Array<int> array;
//			
//			const size_t expected = 0;
//			const size_t actual = array.size();
//			Assert::AreEqual(expected, actual, L"", LINE_INFO());
//		}
//
//		TEST_METHOD(sizeTest02)
//		{
//			Array<int> array;
//
//			for (int i = 0; i < 10; ++i)
//			{
//				array.pushBack(i);
//			}
//
//			const size_t expected = 10;
//			const size_t actual = array.size();
//			Assert::AreEqual(expected, actual, L"", LINE_INFO());
//		}
//
//		TEST_METHOD(isEmptyTest)
//		{
//			Array<int> array;
//
//			const bool expected = true;
//			const bool actual = array.isEmpty();
//			Assert::AreEqual(expected, actual, L"", LINE_INFO());
//		}
//
//		TEST_METHOD(isNotEmptyTest)
//		{
//			Array<int> array;
//
//			array.pushBack(1);
//
//			const bool expected = false;
//			const bool actual = array.isEmpty();
//			Assert::AreEqual(expected, actual, L"", LINE_INFO());
//		}
//
//		TEST_METHOD(isFullTest)
//		{
//			Array<int> array(10);
//
//			for (int i = 0; i < array.size(); ++i)
//			{
//				array.pushBack(i);
//			}
//
//			const bool expected = true;
//			const bool actual = array.isFull();
//			Assert::AreEqual(expected, actual, L"", LINE_INFO());
//		}
//
//		TEST_METHOD(isNotFullTest)
//		{
//			Array<int> array;
//
//			array.pushBack(1);
//
//			const bool expected = false;
//			const bool actual = array.isFull();
//			Assert::AreEqual(expected, actual, L"", LINE_INFO());
//		}
//
//		TEST_METHOD(pushBackTest)
//		{
//			Array<int> array;
//
//			array.pushBack(16);
//
//			const std::string expected = "16 ";
//			const std::string actual = toString(array);
//			Assert::AreEqual(expected, actual, L"", LINE_INFO());
//		}
//
//		TEST_METHOD(popBackTest)
//		{
//			Array<int> array;
//
//			array.pushBack(10);
//
//			array.popBack();
//
//			const bool expected = true;
//			const bool actual = array.isEmpty();
//			Assert::AreEqual(expected, actual, L"", LINE_INFO());
//		}
//
//		TEST_METHOD(insertTestBegin)
//		{
//			Array<int> array;
//
//			Array<int>::iterator itr = array.begin();
//
//			array.pushBack(0);
//			array.pushBack(1);
//			array.pushBack(3);
//			array.pushBack(4);
//
//			array.insert(itr, 2);
//
//			const std::string expected("2 0 1 3 4 ");
//			const std::string actual = toString(array);
//			Assert::AreEqual(expected, actual, L"", LINE_INFO());
//		}
//
//		TEST_METHOD(insertTestMiddle)
//		{
//			Array<int> array;
//
//			Array<int>::iterator itr = array.begin() + 2;
//
//			array.pushBack(0);
//			array.pushBack(1);
//			array.pushBack(3);
//			array.pushBack(4);
//
//			array.insert(itr, 2);
//
//			const std::string expected("0 1 2 3 4 ");
//			const std::string actual = toString(array);
//			Assert::AreEqual(expected, actual, L"", LINE_INFO());
//		}
//
//		TEST_METHOD(insertTestEnd)
//		{
//			Array<int> array;
//
//			Array<int>::iterator itr = array.begin() + 3;
//
//			array.pushBack(0);
//			array.pushBack(1);
//			array.pushBack(3);
//			array.pushBack(4);
//
//			array.insert(itr, 2);
//
//			const std::string expected("0 1 3 2 4 ");
//			const std::string actual = toString(array);
//			Assert::AreEqual(expected, actual, L"", LINE_INFO());
//		}
//
//		TEST_METHOD(eraseTestBegin)
//		{
//			Array<int> array;
//
//			Array<int>::iterator itr = array.begin();
//
//			array.pushBack(0);
//			array.pushBack(1);
//			array.pushBack(2);
//			array.pushBack(3);
//
//			array.erase(itr);
//
//			const std::string expected("1 2 3 ");
//			const std::string actual = toString(array);
//			Assert::AreEqual(expected, actual, L"", LINE_INFO());
//		}
//
//		TEST_METHOD(eraseTestMiddle)
//		{
//			Array<int> array;
//
//			Array<int>::iterator itr = array.begin() + 1;
//
//			array.pushBack(0);
//			array.pushBack(1);
//			array.pushBack(2);
//			array.pushBack(3);
//
//			array.erase(itr);
//
//			const std::string expected("0 2 3 ");
//			const std::string actual = toString(array);
//			Assert::AreEqual(expected, actual, L"", LINE_INFO());
//		}
//
//		TEST_METHOD(eraseTestEnd)
//		{
//			Array<int> array;
//
//			Array<int>::iterator itr = array.begin() + 3;
//
//			array.pushBack(0);
//			array.pushBack(1);
//			array.pushBack(2);
//			array.pushBack(3);
//
//			array.erase(itr);
//
//			const std::string expected("0 1 2 ");
//			const std::string actual = toString(array);
//			Assert::AreEqual(expected, actual, L"", LINE_INFO());
//		}
//
//		TEST_METHOD(get_by_index)
//		{
//			Array<int> array;
//
//			array.pushBack(16);
//
//			const int expected = 16;
//			const int actual = array[0];
//			Assert::AreEqual(expected, actual, L"", LINE_INFO());
//		}
//
//		TEST_METHOD(out_of_range_Test)
//		{
//			Array<int> array;
//
//			array.pushBack(10);
//
//			try
//			{
//				array[1000000];
//
//			}
//			catch (std::out_of_range& e)
//			{
//				const std::string expected("Index is Out of Range");
//				const std::string actual(e.what());
//				Assert::AreEqual(expected, actual, L"", LINE_INFO());
//			}
//		}
//		
//		TEST_METHOD(overflow_error_pushBack_Test)
//		{
//			Array<int> arr;
//
//			for (int i = 0; i < SIZE; ++i)
//			{
//				arr.pushBack(i);
//			}
//
//			try
//			{
//				arr.pushBack(10);
//			}
//			catch (const std::overflow_error& error)
//			{
//				const std::string expected("Stack is Full!");
//				const std::string actual(error.what());
//				Assert::AreEqual(expected, actual, L"", LINE_INFO());
//			}
//		}
//
//
//		TEST_METHOD(overflow_error_insert_Test)
//		{
//			Array<int> arr;
//
//			for (int i = 0; i < SIZE; ++i)
//			{
//				arr.pushBack(i);
//			}
//
//			try
//			{
//				arr.insert(arr.begin() + 2, 11);
//			}
//			catch (const std::overflow_error& error)
//			{
//				const std::string expected("Stack is Full!");
//				const std::string actual(error.what());
//				Assert::AreEqual(expected, actual, L"", LINE_INFO());
//			}
//		}
//
//		TEST_METHOD(underflow_error_popBack_Test)
//		{
//			Array<int> arr;
//
//			try
//			{
//				arr.popBack();
//			}
//			catch (const std::underflow_error& error)
//			{
//				const std::string expected("Stack is Empty!");
//				const std::string actual(error.what());
//				Assert::AreEqual(expected, actual, L"", LINE_INFO());
//			}
//		}
//
//		TEST_METHOD(underflow_error_erase_Test)
//		{
//			Array<int> arr;
//
//			try
//			{
//				arr.erase(arr.begin());
//			}
//			catch (const std::underflow_error& error)
//			{
//				const std::string expected("Stack is Empty!");
//				const std::string actual(error.what());
//				Assert::AreEqual(expected, actual, L"", LINE_INFO());
//			}
//		}
//	};
//}