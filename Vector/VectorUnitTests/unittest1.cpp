#include "stdafx.h"
//#include "CppUnitTest.h"
//#include "Vector.h"
//#include <string>
//
//using namespace Microsoft::VisualStudio::CppUnitTestFramework;
//
//namespace VectorUnitTests
//{		
//	TEST_CLASS(VectorTests)
//	{
//	private:
//		static std::string toString(Vector<int>& vector)
//		{
//			std::string result = "";
//
//			for (int i = 0; i < vector.size(); ++i)
//			{
//				int value = vector[i];
//
//				result += std::to_string(value);
//				result += " ";
//			}
//
//			return result;
//		}
//
//	public:		
//		TEST_METHOD(CTOR)
//		{
//			Vector<int> vector;
//		}
//
//		TEST_METHOD(CCTORValueTest)
//		{
//			Vector<int> vector1;
//
//			vector1.pushBack(10);
//			vector1.pushBack(20);
//			vector1.pushBack(30);
//
//			Vector<int> vector2(vector1);
//
//			vector1.popBack();
//
//			const std::string expected = "10 20 30 ";
//			const std::string actual = toString(vector2);
//			Assert::AreEqual(expected, actual, L"", LINE_INFO());
//		}
//
//		TEST_METHOD(CCTORBeginTest)
//		{
//			Vector<int> vector1;
//
//			vector1.pushBack(10);
//			vector1.pushBack(20);
//			vector1.pushBack(30);
//
//			Vector<int> vector2(vector1);
//
//			const int expected = 10;
//			const int actual = *vector2.begin();
//			Assert::AreEqual(expected, actual, L"", LINE_INFO());
//		}
//
//		TEST_METHOD(CCTOREndTest)
//		{
//			Vector<int> vector1;
//
//			vector1.pushBack(10);
//			vector1.pushBack(20);
//			vector1.pushBack(30);
//
//			Vector<int> vector2(vector1);
//			
//			const int expected = 30;
//			const int actual = *(vector2.end() - 1);
//			Assert::AreEqual(expected, actual, L"", LINE_INFO());
//		}
//
//		TEST_METHOD(operatorEqualValueTest)
//		{
//			Vector<int> vector1;
//
//			vector1.pushBack(10);
//			vector1.pushBack(20);
//			vector1.pushBack(30);
//
//			Vector<int> vector2;
//
//			vector2 = vector1;
//
//			const std::string expected = "10 20 30 ";
//			const std::string actual = toString(vector2);
//			Assert::AreEqual(expected, actual, L"", LINE_INFO());
//		}
//
//		TEST_METHOD(operatorEqualBeginTest)
//		{
//			Vector<int> vector1;
//
//			vector1.pushBack(10);
//			vector1.pushBack(20);
//			vector1.pushBack(30);
//
//			Vector<int> vector2;
//
//			vector2 = vector1;
//
//			const int expected = 10;
//			const int actual = *vector2.begin();
//			Assert::AreEqual(expected, actual, L"", LINE_INFO());
//		}
//
//		TEST_METHOD(operatorEqualEndTest)
//		{
//			Vector<int> vector1;
//
//			vector1.pushBack(10);
//			vector1.pushBack(20);
//			vector1.pushBack(30);
//
//			Vector<int> vector2;
//
//			vector2 = vector1;
//
//			const int expected = 30;
//			const int actual = *(vector2.end() - 1);
//			Assert::AreEqual(expected, actual, L"", LINE_INFO());
//		}
//
//		TEST_METHOD(sizeTest01)
//		{
//			Vector<std::string> vector;
//
//			const int expected = 0;
//			const int actual = vector.size();
//			Assert::AreEqual(expected, actual, L"", LINE_INFO());
//		}
//
//		TEST_METHOD(sizeTest02)
//		{
//			Vector<std::string> vector;
//
//			vector.pushBack("A");
//			vector.pushBack("B");
//			vector.pushBack("C");
//			vector.pushBack("D");
//
//			const int expected = 4;
//			const int actual = vector.size();
//			Assert::AreEqual(expected, actual, L"", LINE_INFO());
//		}
//
//		TEST_METHOD(pushBackTest)
//		{
//			Vector<int> vector;
//
//			vector.pushBack(10);
//			vector.pushBack(20);
//			vector.pushBack(30);
//			vector.pushBack(40);
//
//			const std::string expected = "10 20 30 40 ";
//			const std::string actual = toString(vector);
//			Assert::AreEqual(expected, actual, L"", LINE_INFO());
//		}
//
//		TEST_METHOD(popBackTest)
//		{
//			Vector<int> vector;
//
//			vector.pushBack(10);
//			vector.pushBack(20);
//			vector.pushBack(30);
//			vector.pushBack(40);
//
//			vector.popBack();
//
//			const std::string expected = "10 20 30 ";
//			const std::string actual = toString(vector);
//			Assert::AreEqual(expected, actual, L"", LINE_INFO());
//		}
//
//		TEST_METHOD(insertTest)
//		{
//			Vector<int> vector;
//
//			vector.pushBack(10);
//			vector.pushBack(20);
//			vector.pushBack(30);
//			vector.pushBack(40);
//
//			vector.insert(vector.begin() + 2, 50);
//
//			const std::string expected = "10 20 50 30 40 ";
//			const std::string actual = toString(vector);
//			Assert::AreEqual(expected, actual, L"", LINE_INFO());
//		}
//
//		TEST_METHOD(eraseTest)
//		{
//			Vector<int> vector;
//
//			vector.pushBack(10);
//			vector.pushBack(20);
//			vector.pushBack(30);
//			vector.pushBack(40);
//
//			vector.erase(vector.begin());
//
//			const std::string expected = "20 30 40 ";
//			const std::string actual = toString(vector);
//			Assert::AreEqual(expected, actual, L"", LINE_INFO());
//		}
//
//		TEST_METHOD(isEmptyTest)
//		{
//			Vector<int> vector;
//
//			const bool expected = true;
//			const bool actual = vector.isEmpty();
//			Assert::AreEqual(expected, actual, L"", LINE_INFO());
//		}
//
//		TEST_METHOD(isNotEmptyTest)
//		{
//			Vector<int> vector;
//
//			vector.pushBack(10);
//
//			const bool expected = false;
//			const bool actual = vector.isEmpty();
//			Assert::AreEqual(expected, actual, L"", LINE_INFO());
//		}
//
//		TEST_METHOD(outOfRangeErrorTest)
//		{
//			Vector<int> vector;
//
//			try
//			{
//				vector[10000];
//			}
//			catch (const std::out_of_range& e)
//			{
//				const std::string expected("Index is Out of Range!");
//				const std::string actual(e.what());
//				Assert::AreEqual(expected, actual, L"", LINE_INFO());
//			}
//		}
//
//		TEST_METHOD(underflow_error_Test01)
//		{
//			Vector<int> vector;
//
//			try
//			{
//				vector.popBack();
//			}
//			catch (const std::underflow_error& e)
//			{
//				const std::string expected("Stack is Empty!");
//				const std::string actual(e.what());
//				Assert::AreEqual(expected, actual, L"", LINE_INFO());
//			}
//		}
//
//		TEST_METHOD(underflow_error_Test02)
//		{
//			Vector<int> vector;
//
//			try
//			{
//				vector.erase(vector.begin());
//			}
//			catch (const std::underflow_error& e)
//			{
//				const std::string expected("Stack is Empty!");
//				const std::string actual(e.what());
//				Assert::AreEqual(expected, actual, L"", LINE_INFO());
//			}
//		}
//	};
//}