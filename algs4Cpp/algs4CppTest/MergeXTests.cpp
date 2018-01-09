#include "stdafx.h"
#include "CppUnitTest.h"
#include"..\algs4Cpp\MergeX.h"
#include<fstream>
#include<string>
#include<algorithm>


using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using algs4Cpp::MergeX;
using std::ifstream;
using std::string;
using std::vector;


namespace algs4CppTest
{
	TEST_CLASS(MergeXTests)
	{
	public:

		TEST_METHOD(MergeXTest1)
		{
			ifstream input("tiny.txt");
			vector<string> svec;
			string s;
			while (input >> s) {
				svec.push_back(s);
			}
			vector<string> cvec1(svec);
			MergeX<string>::sort(svec);
			std::sort(cvec1.begin(), cvec1.end());
			Assert::IsTrue(svec == cvec1);

		}

	};
}