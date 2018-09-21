#include "stdafx.h"
#include "CppUnitTest.h"
#include "Stack.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace StackUnitTests
{		
	TEST_CLASS(UnitTestForInt)
	{
	private:
		static std::string toString(Stack<int>& stack)
		{
			std::string result = "";
			while (stack.size() != 0)
			{
				result += std::to_string(stack.top());
				result += " ";
				stack.pop();
			}
			return result;
		}

	public:

		TEST_METHOD(CTOR)
		{
			Stack<int> stack;
		}

		TEST_METHOD(copyCTORTopTest)
		{
			Stack<int> stack1;

			stack1.push(10);

			Stack<int> stack2(stack1);

			const int expected = 10;
			const int actual = stack2.top();
			Assert::AreEqual(expected, actual, L"", LINE_INFO());
		}

		TEST_METHOD(copyCTORByValue)
		{
			Stack<int> stack1;

			stack1.push(10);
			stack1.push(20);
			stack1.push(30);

			Stack<int> stack2(stack1);

			stack2.push(40);
			stack1.pop();

			const std::string expected = "40 30 20 10 ";
			const std::string actual = toString(stack2);
			Assert::AreEqual(expected, actual, L"", LINE_INFO());
		}

		TEST_METHOD(copyCTORSizeTest)
		{
			Stack<int> stack1;

			stack1.push(10);
			stack1.push(20);
			stack1.push(30);

			Stack<int> stack2(stack1);

			stack2.push(40);
			stack2.pop();

			const int expected = 3;
			const int actual = stack2.size();
			Assert::AreEqual(expected, actual, L"", LINE_INFO());
		}

		TEST_METHOD(operatorEqualTopTest)
		{
			Stack<int> stack1;

			stack1.push(10);

			Stack<int> stack2;

			stack2 = stack1;

			const int expected = 10;
			const int actual = stack2.top();
			Assert::AreEqual(expected, actual, L"", LINE_INFO());
		}

		TEST_METHOD(operatorEqualByValue)
		{
			Stack<int> stack1;

			stack1.push(10);
			stack1.push(20);
			stack1.push(30);

			Stack<int> stack2;

			stack2 = stack1;

			stack2.push(40);
			stack1.pop();

			const std::string expected = "40 30 20 10 ";
			const std::string actual = toString(stack2);
			Assert::AreEqual(expected, actual, L"", LINE_INFO());
		}

		TEST_METHOD(operatorEqualSizeTest)
		{
			Stack<int> stack1;

			stack1.push(10);
			stack1.push(20);
			stack1.push(30);

			Stack<int> stack2;

			stack2 = stack1;

			stack2.push(40);
			stack2.pop();

			const int expected = 3;
			const int actual = stack2.size();
			Assert::AreEqual(expected, actual, L"", LINE_INFO());
		}

		TEST_METHOD(pushTest)
		{
			Stack<int> stack;

			stack.push(10);

			const int expected = 10;
			const int actual = stack.top();
			Assert::AreEqual(expected, actual, L"", LINE_INFO());
		}

		TEST_METHOD(pushTestByValue)
		{
			Stack<int> stack;

			stack.push(10);
			stack.push(20);
			stack.push(30);
			stack.push(40);

			const std::string expected = "40 30 20 10 ";
			const std::string actual = toString(stack);
			Assert::AreEqual(expected, actual, L"", LINE_INFO());
		}

		TEST_METHOD(pushSizeTest)
		{
			Stack<int> stack;

			stack.push(10);
			stack.push(20);
			stack.push(30);

			const int expected = 3;
			const int actual = stack.size();
			Assert::AreEqual(expected, actual, L"", LINE_INFO());
		}

		TEST_METHOD(popTest)
		{
			Stack<int> stack;

			stack.push(10);
			stack.push(20);
			stack.push(30);

			stack.pop();

			const std::string expected = "20 10 ";
			const std::string actual = toString(stack);
			Assert::AreEqual(expected, actual, L"", LINE_INFO());
		}

		TEST_METHOD(popSizeTest)
		{
			Stack<int> stack;

			stack.push(10);
			stack.push(20);
			stack.push(30);

			stack.pop();

			const int expected = 2;
			const int actual = stack.size();
			Assert::AreEqual(expected, actual, L"", LINE_INFO());
		}

		TEST_METHOD(IsEmptyFalseTest)
		{
			Stack<int> stack;

			stack.push(10);
			stack.push(20);
			stack.push(30);

			stack.pop();

			const int expected = false;
			const int actual = stack.isEmpty();
			Assert::AreEqual(expected, actual, L"", LINE_INFO());
		}

		TEST_METHOD(IsEmptyTrueTest)
		{
			Stack<int> stack;

			stack.push(10);

			stack.pop();

			const int expected = true;
			const int actual = stack.isEmpty();
			Assert::AreEqual(expected, actual, L"", LINE_INFO());
		}

		TEST_METHOD(sizeEmptyTest)
		{
			Stack<int> stack;

			const int expected = 0;
			const int actual = stack.size();
			Assert::AreEqual(expected, actual, L"", LINE_INFO());
		}

		TEST_METHOD(sizeTest)
		{
			Stack<int> stack;

			stack.push(10);
			stack.push(20);
			stack.push(30);

			const int expected = 3;
			const int actual = stack.size();
			Assert::AreEqual(expected, actual, L"", LINE_INFO());
		}

		TEST_METHOD(underflowErrorTest)
		{
			Stack<int> stack;

			try
			{
				stack.pop();
			}
			catch (const std::underflow_error& e)
			{
				const std::string expected = "Stack is Empty!";
				const std::string actual(e.what());
				Assert::AreEqual(expected, actual, L"", LINE_INFO());
			}
		}
	};
}