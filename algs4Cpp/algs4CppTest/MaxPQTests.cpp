#include "stdafx.h"
#include "CppUnitTest.h"
#include"..\algs4Cpp\MaxPQ.h"
#include<vector>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using algs4Cpp::MaxPQ;
using std::vector;

namespace algs4CppTest
{
	TEST_CLASS(MaxPQTests)
	{
	public:

		TEST_METHOD(MaxPQTest1)
		{
			MaxPQ<int> pq{ 0,1,2,3,4,5,6,7,8,9 };
			MaxPQ<int> pq2(vector<int>{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 });
			Assert::IsTrue(pq.size() == pq2.size(), L"", LINE_INFO());
			for (auto it = pq.begin(), it2 = pq2.begin(); it != pq.end() && it2 != pq2.end();++it,++it2)
				Assert::IsTrue(*it == *it2, L"", LINE_INFO());

			for (size_t i = 0; i != pq2.size(); ++i) {
				int max = pq.max();
				Assert::IsTrue(max == pq.delMax(), L"", LINE_INFO());
				Assert::IsTrue(pq.size()==9-i, L"", LINE_INFO());
			}

			Assert::IsTrue(pq.isEmpty(), L"", LINE_INFO());

			for (size_t i = 0; i != pq2.size(); ++i) {
				pq.insert(i);
				Assert::IsTrue(pq.max() == i, L"", LINE_INFO());
			}

			Assert::IsTrue(pq2.keys() == vector<int>{9, 8, 7, 6, 5, 4, 3, 2, 1, 0}, L"", LINE_INFO());
		}

	};
}
