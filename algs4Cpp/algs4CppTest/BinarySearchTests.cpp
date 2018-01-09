#include "stdafx.h"
#include "CppUnitTest.h"
#include"..\algs4Cpp\BinarySearch.h"
#include<vector>


using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using std::vector;
using algs4Cpp::BinarySearch;

namespace algs4CppTest
{
	TEST_CLASS(BinarySearchTests)
	{
	public:

		TEST_METHOD(BinarySearchTest1)
		{
			vector<int> a{ 2, 4, 6, 8, 10, 12, 14, 16, 18, 22 };
			Assert::AreEqual(-1, BinarySearch::indexOf(a, 1));
			Assert::AreEqual(-1, BinarySearch::indexOf(a, 20));
			Assert::AreEqual(-1, BinarySearch::indexOf(a, 25));
			Assert::AreEqual(1, BinarySearch::indexOf(a, 4));
			Assert::AreEqual(5, BinarySearch::indexOf(a, 12));
			Assert::AreEqual(9, BinarySearch::indexOf(a, 22));
		}

	};
}