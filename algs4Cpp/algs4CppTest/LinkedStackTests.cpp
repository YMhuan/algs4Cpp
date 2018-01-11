#include "stdafx.h"
#include "CppUnitTest.h"
#include"..\algs4Cpp\LinkedStack.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using algs4Cpp::LinkedStack;

namespace algs4CppTest
{
	TEST_CLASS(LinkedStackTests)
	{
	public:

		TEST_METHOD(LinkedStackTest1)
		{
			LinkedStack<int> stack;
			stack.push(3);
			Assert::IsTrue(stack.peek() == 3,L"",LINE_INFO());

			stack.push(4);
			Assert::IsTrue(stack.peek() == 4,L"",LINE_INFO());

			Assert::IsTrue(stack.pop() == 4, L"", LINE_INFO());
			Assert::IsTrue(stack.pop() == 3, L"", LINE_INFO());
			Assert::IsTrue(stack.size() == 0, L"", LINE_INFO());

			for (int i = 0; i != 5; ++i) {
				stack.push(i);
			}
			bool consistent = true;
			int i = 5;
			for (auto beg = stack.begin(),end = stack.end(); beg != end; ++beg) {
				if (*beg != --i) consistent = false;
			}
			Assert::IsTrue(consistent == true, L"", LINE_INFO());
		}

	};
}
