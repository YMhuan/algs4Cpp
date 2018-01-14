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
			Assert::IsTrue(BinarySearch<int>::indexOf(a, 1)==-1, L"", LINE_INFO());
			Assert::IsTrue(BinarySearch<int>::indexOf(a, 20)==-1, L"", LINE_INFO());
			Assert::IsTrue(BinarySearch<int>::indexOf(a, 25)==-1, L"", LINE_INFO());
			Assert::IsTrue(BinarySearch<int>::indexOf(a, 4)==1, L"", LINE_INFO());
			Assert::IsTrue(BinarySearch<int>::indexOf(a, 12)==5, L"", LINE_INFO());
			Assert::IsTrue(BinarySearch<int>::indexOf(a, 22)==9, L"", LINE_INFO());
		}

	};
}
