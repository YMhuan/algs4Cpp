#include "stdafx.h"
#include "CppUnitTest.h"
#include"..\algs4Cpp\Merge.h"
#include<fstream>
#include<string>
#include<algorithm>


using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using algs4Cpp::Merge;
using std::ifstream;
using std::string;
using std::vector;


namespace algs4CppTest
{
	TEST_CLASS(MergeTests)
	{
	public:

		TEST_METHOD(MergeTest1)
		{
			ifstream input("tiny.txt");
			vector<string> svec;
			string s;
			while (input >> s) {
				svec.push_back(s);
			}
			vector<string> cvec1(svec);
			vector<string> cvec2(svec);
			Merge<string>::sort(svec);
			std::stable_sort(cvec1.begin(), cvec1.end());
			Assert::IsTrue(svec == cvec1, L"", LINE_INFO());


			vector<int> index1 = Merge<string>::indexSort(cvec2);
			vector<int> index2;
			index2.reserve(cvec2.size());
			for (int i = 0; i != cvec2.size(); ++i) {
				index2.push_back(i);
			}
			std::stable_sort(index2.begin(), index2.end(), [&cvec2](int a, int b) {return cvec2[a] < cvec2[b]; });
			Assert::IsTrue(index1 == index2, L"", LINE_INFO());
		}

	};
}
