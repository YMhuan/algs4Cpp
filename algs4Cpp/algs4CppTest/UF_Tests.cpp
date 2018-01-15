#include "stdafx.h"
#include "CppUnitTest.h"
#include"..\algs4Cpp\UF.h"
#include<utility>
#include<vector>


using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using std::vector;
using std::pair;
using std::make_pair;
using std::exception;
using algs4Cpp::UF;



namespace algs4CppTest
{		
	TEST_CLASS(UFTests)
	{
	private:
		UF unionSite(vector<pair<int, int>> links, int N)
		{
			UF uf(N);
			for (auto pair : links) 
			{
				int p = pair.first;
				int q = pair.second;
				if (uf.connected(p, q)) continue;
				uf.unionSite(p, q);
			}
			return uf;
		}
	public:
		
		TEST_METHOD(UFTest1)
		{
			vector<pair<int, int>> set1
			{
				make_pair(1,1),
				make_pair(2,2),
				make_pair(3,3),
				make_pair(0,0)
			};
			
			UF uf = unionSite(set1, set1.size());
			Assert::IsTrue(uf.siteCount()==set1.size(), L"", LINE_INFO());

			vector<pair<int, int>> set2
			{
				make_pair(0,1),
				make_pair(2,3),
				make_pair(4,5),
				make_pair(6,0),
				make_pair(7,1)
			};
			uf = unionSite(set2, 8);

			Assert::IsTrue(uf.siteCount()==3, L"", LINE_INFO());


			auto funcPtr = [&]() {
				set2[0] = make_pair(7, 8);
				uf = unionSite(set2, 8);
			};
			Assert::ExpectException<std::out_of_range>(funcPtr, L"", LINE_INFO());
		}

	};
}