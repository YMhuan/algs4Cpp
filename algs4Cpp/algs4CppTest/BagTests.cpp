#include "stdafx.h"
#include "CppUnitTest.h"
#include"..\algs4Cpp\Bag.h"
#include<vector>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using algs4Cpp::Bag;
using std::vector;

namespace algs4CppTest
{
	TEST_CLASS(BagTests)
	{
	public:

		TEST_METHOD(BagTest1)
		{
			vector<int> expected;
			Bag<int> bag;
			vector<int> sb;
			for (int s : bag) {
				sb.push_back(s);
			}
			Assert::IsTrue(bag.isEmpty());
			Assert::IsTrue(expected==sb);

			bag.add(3);
			expected.push_back(3);
			sb.clear();
			for (int s : bag) {
				sb.push_back(s);
			}
			Assert::IsTrue(expected == sb);

			bag.add(2);
			bag.add(3);
			Assert::IsFalse(bag.isEmpty());
			Assert::AreEqual(3, bag.size());
			expected.push_back(2);
			expected.push_back(3);
			sb.clear();
			for (int s : bag) {
				sb.push_back(s);
			}
			Assert::IsTrue(expected == sb);

		}

	};
}
