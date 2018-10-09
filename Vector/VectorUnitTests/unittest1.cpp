#include "stdafx.h"
#include "CppUnitTest.h"
#include "Vector.h"
#include <string>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace VectorUnitTests
{
	TEST_CLASS(VectorTests)
	{
	private:
		static std::string toString(DataStructure::Vector<int>& vector)
		{
			std::string result = "";

			for (int i = 0; i < vector.size(); ++i)
			{
				int value = vector[i];

				result += std::to_string(value);
				result += " ";
			}

			return result;
		}

	public:		
		TEST_METHOD(CTOR)
		{
			DataStructure::Vector<int> vector;
		}

		TEST_METHOD(CCTORValueTest)
		{
			DataStructure::Vector<int> vector1;

			vector1.pushBack(10);
			vector1.pushBack(20);
			vector1.pushBack(30);

			DataStructure::Vector<int> vector2(vector1);

			vector1.popBack();

			const std::string expected = "10 20 30 ";
			const std::string actual = toString(vector2);
			Assert::AreEqual(expected, actual, L"", LINE_INFO());
		}

		TEST_METHOD(CCTORBeginTest)
		{
			DataStructure::Vector<int> vector1;

			vector1.pushBack(10);
			vector1.pushBack(20);
			vector1.pushBack(30);

			DataStructure::Vector<int> vector2(vector1);

			const int expected = 10;
			const int actual = *vector2.begin();
			Assert::AreEqual(expected, actual, L"", LINE_INFO());
		}

		TEST_METHOD(CCTOREndTest)
		{
			DataStructure::Vector<int> vector1;

			vector1.pushBack(10);
			vector1.pushBack(20);
			vector1.pushBack(30);

			DataStructure::Vector<int> vector2(vector1);
			
			const int expected = 30;
			const int actual = *(vector2.end() - 1);
			Assert::AreEqual(expected, actual, L"", LINE_INFO());
		}

		TEST_METHOD(operatorEqualValueTest)
		{
			DataStructure::Vector<int> vector1;

			vector1.pushBack(10);
			vector1.pushBack(20);
			vector1.pushBack(30);

			DataStructure::Vector<int> vector2;

			vector2 = vector1;

			const std::string expected = "10 20 30 ";
			const std::string actual = toString(vector2);
			Assert::AreEqual(expected, actual, L"", LINE_INFO());
		}

		TEST_METHOD(operatorEqualBeginTest)
		{
			DataStructure::Vector<int> vector1;

			vector1.pushBack(10);
			vector1.pushBack(20);
			vector1.pushBack(30);

			DataStructure::Vector<int> vector2;

			vector2 = vector1;

			const int expected = 10;
			const int actual = *vector2.begin();
			Assert::AreEqual(expected, actual, L"", LINE_INFO());
		}

		TEST_METHOD(operatorEqualEndTest)
		{
			DataStructure::Vector<int> vector1;

			vector1.pushBack(10);
			vector1.pushBack(20);
			vector1.pushBack(30);

			DataStructure::Vector<int> vector2;

			vector2 = vector1;

			const size_t expected = 30;
			const size_t actual = *(vector2.end() - 1);
			Assert::AreEqual(expected, actual, L"", LINE_INFO());
		}

		TEST_METHOD(sizeTest01)
		{
			DataStructure::Vector<std::string> vector;

			const size_t expected = 0;
			const size_t actual = vector.size();
			Assert::AreEqual(expected, actual, L"", LINE_INFO());
		}

		TEST_METHOD(sizeTest02)
		{
			DataStructure::Vector<std::string> vector;

			vector.pushBack("A");
			vector.pushBack("B");
			vector.pushBack("C");
			vector.pushBack("D");

			const size_t expected = 4;
			const size_t actual = vector.size();
			Assert::AreEqual(expected, actual, L"", LINE_INFO());
		}

		TEST_METHOD(pushBackTest)
		{
			DataStructure::Vector<int> vector;

			vector.pushBack(10);
			vector.pushBack(20);
			vector.pushBack(30);
			vector.pushBack(40);

			const std::string expected = "10 20 30 40 ";
			const std::string actual = toString(vector);
			Assert::AreEqual(expected, actual, L"", LINE_INFO());
		}

		TEST_METHOD(popBackTest)
		{
			DataStructure::Vector<int> vector;

			vector.pushBack(10);
			vector.pushBack(20);
			vector.pushBack(30);
			vector.pushBack(40);

			vector.popBack();

			const std::string expected = "10 20 30 ";
			const std::string actual = toString(vector);
			Assert::AreEqual(expected, actual, L"", LINE_INFO());
		}

		TEST_METHOD(insertFromBeginTest)
		{
			DataStructure::Vector<int> vector;

			vector.pushBack(10);
			vector.pushBack(20);
			vector.pushBack(30);
			vector.pushBack(40);

			vector.insert(vector.begin(), 50);

			const std::string expected = "50 10 20 30 40 ";
			const std::string actual = toString(vector);
			Assert::AreEqual(expected, actual, L"", LINE_INFO());
		}

		TEST_METHOD(insertFromMiddleTest)
		{
			DataStructure::Vector<int> vector;

			vector.pushBack(10);
			vector.pushBack(20);
			vector.pushBack(30);
			vector.pushBack(40);

			vector.insert(vector.begin() + 2, 50);

			const std::string expected = "10 20 50 30 40 ";
			const std::string actual = toString(vector);
			Assert::AreEqual(expected, actual, L"", LINE_INFO());
		}

		TEST_METHOD(insertFromEndTest)
		{
			DataStructure::Vector<int> vector;

			vector.pushBack(10);
			vector.pushBack(20);
			vector.pushBack(30);
			vector.pushBack(40);

			vector.insert(vector.end(), 50);

			const std::string expected = "10 20 30 40 50 ";
			const std::string actual = toString(vector);
			Assert::AreEqual(expected, actual, L"", LINE_INFO());
		}

		TEST_METHOD(eraseFromBeginTest)
		{
			DataStructure::Vector<int> vector;

			vector.pushBack(10);
			vector.pushBack(20);
			vector.pushBack(30);
			vector.pushBack(40);

			vector.erase(vector.begin());

			const std::string expected = "20 30 40 ";
			const std::string actual = toString(vector);
			Assert::AreEqual(expected, actual, L"", LINE_INFO());
		}

		TEST_METHOD(eraseFromMiddleTest)
		{
			DataStructure::Vector<int> vector;

			vector.pushBack(10);
			vector.pushBack(20);
			vector.pushBack(30);
			vector.pushBack(40);

			vector.erase(vector.begin() + 1);

			const std::string expected = "10 30 40 ";
			const std::string actual = toString(vector);
			Assert::AreEqual(expected, actual, L"", LINE_INFO());
		}

		TEST_METHOD(eraseFromEndTest)
		{
			DataStructure::Vector<int> vector;

			vector.pushBack(10);
			vector.pushBack(20);
			vector.pushBack(30);
			vector.pushBack(40);

			vector.erase(vector.end() - 1);

			const std::string expected = "10 20 30 ";
			const std::string actual = toString(vector);
			Assert::AreEqual(expected, actual, L"", LINE_INFO());
		}

		TEST_METHOD(isEmptyTest)
		{
			DataStructure::Vector<int> vector;

			const bool expected = true;
			const bool actual = vector.empty();
			Assert::AreEqual(expected, actual, L"", LINE_INFO());
		}

		TEST_METHOD(isNotEmptyTest)
		{
			DataStructure::Vector<int> vector;

			vector.pushBack(10);

			const bool expected = false;
			const bool actual = vector.empty();
			Assert::AreEqual(expected, actual, L"", LINE_INFO());
		}

		TEST_METHOD(outOfRangeErrorTest)
		{
			DataStructure::Vector<int> vector;

			try
			{
				vector[10000];
			}
			catch (const std::out_of_range& e)
			{
				const std::string expected("Out of Range!");
				const std::string actual(e.what());
				Assert::AreEqual(expected, actual, L"", LINE_INFO());
			}
		}
	};
}